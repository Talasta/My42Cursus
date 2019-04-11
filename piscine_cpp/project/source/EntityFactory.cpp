#include "EntityFactory.hpp"

#include "ComponentAI.hpp"
#include "ComponentAnimation.hpp"
#include "ComponentCollisionBox.hpp"
#include "ComponentCollisionBoxPlayer.hpp"
#include "ComponentHealth.hpp"
#include "ComponentMove.hpp"
#include "ComponentPlayerControl.hpp"
#include "ComponentRender.hpp"
#include "ComponentScript.hpp"
#include "ComponentSpawner.hpp"
#include "ComponentText.hpp"
#include "ComponentTextUI.hpp"
#include "ComponentTimer.hpp"

#define ADD(x) addFunction(#x, &Entity::x)


EntityFactory* entityFactory;

EntityFactory::EntityFactory()
{
    entityFactory = this;

    L = luaL_newstate();
    luaL_openlibs(L);

    lua_newtable(L);
    lua_setglobal(L, "message");
    lua_getglobal(L, "message");
    std::string messageTypes[4] = { "eventCallback", "hit", "setMove", "use" };
    for(unsigned char i = 0; i != 4; ++i)
    {
        lua_pushnumber(L, i);
        lua_setfield(L, -2, messageTypes[i].c_str());
    }

    luabridge::getGlobalNamespace(L)

    .addFunction("print", &print)

    .addFunction("playSound", &playSound)

    .addFunction("create", &create)
    .addFunction("kill", &kill)

    .addFunction("triggerEvent", &triggerEvent)

    .beginClass<Message>("Message")
    .addConstructor <void(*) (unsigned char)>()
    .addData("type", &Message::type, false)
    .addData("number", &Message::number)
    .addData("string", &Message::string)
    .addData("vector", &Message::vector)
    .endClass()

    .beginClass<Entity>("Entity")

    .ADD(receive)
    .ADD(getPosition)
    .ADD(listenToEvent)

    .ADD(setAnimation)
    .ADD(setBoxSize)
    .ADD(getHealth)
    .ADD(getBaseHealth)
    .ADD(setHealth)
    .ADD(getDirection)
    .ADD(setTransparency)
    .ADD(setScriptState)
    .ADD(setTextString)
    .ADD(setTextColor)
    .ADD(getTimerSecondsElapsed)
    .ADD(restartTimer)
    .endClass()

    .beginClass<sf::Vector2f>("Vector")
    .addConstructor <void(*) (float, float)>()
    .addData("x", &sf::Vector2f::x)
    .addData("y", &sf::Vector2f::y)
    .endClass();
}

EntityFactory::~EntityFactory()
{
    for(Entity* entity : m_templates)
    {
        delete entity;
    }
}

void EntityFactory::loadEntity(const std::string& name)
{
    Entity* entity = new Entity(sf::Vector2f());

    luaL_dofile(L, ("data/script/" + name + ".lua").c_str());

    luabridge::LuaRef global = luabridge::getGlobal(L, name.c_str());

    luabridge::LuaRef table = global["AI"];
    if(!table.isNil())
    {
        entity->addComponent(new AI(table["attackDistance"].cast<unsigned int>(), table["attack"]));
    }

    table = global["Render"];
    if(!table.isNil())
    {
        luabridge::LuaRef texCoords(table["texCoords"]);
        unsigned char z = table["z"].isNil() ? 0 : table["z"].cast<unsigned char>();
        entity->addComponent(new Render(table["filename"].cast<std::string>(),
                                        sf::FloatRect(texCoords[1].cast<unsigned int>(),texCoords[2].cast<unsigned int>(),texCoords[3].cast<unsigned int>(),texCoords[4].cast<unsigned int>()),
                                        z));

        table = global["Animation"];
        if(!table.isNil())
        {
            Animation* anim = new Animation(table["frameTime"].cast<float>());
            luabridge::LuaRef animations = table["animations"];
            for(const std::string& animationName : lua_getTableKeys(L, name + ".Animation.animations"))
            {
                luabridge::LuaRef animation = animations[animationName];
                luabridge::LuaRef texCoords = animation["texCoords"];
                anim->addAnimation(animationName,
                                   animation["frameCount"],
                                   sf::Rect<unsigned int>(texCoords[1].cast<unsigned int>(),texCoords[2].cast<unsigned int>(),texCoords[3].cast<unsigned int>(),texCoords[4].cast<unsigned int>()));
            }
                entity->addComponent(anim);
        }
    }
    else
    {
        table = global["TextUI"];
        if(!table.isNil())
        {
            luabridge::LuaRef color = table["color"];
            entity->addComponent(new TextUI(table["content"].cast<std::string>(), table["charSize"], sf::Color(color[1],color[2],color[3],color[4])));
        }
        else
        {
            table = global["Text"];
            if(!table.isNil())
            {
                luabridge::LuaRef color = table["color"];
                entity->addComponent(new Text(table["content"].cast<std::string>(), table["charSize"], sf::Color(color[1],color[2],color[3],color[4])));
            }
        }
    }


    table = global["CollisionBox"];
    if(!table.isNil())
    {
        luabridge::LuaRef size = table["size"];
        entity->addComponent(new CollisionBox(sf::Vector2f(size[1].cast<unsigned int>(), size[2].cast<unsigned int>()), table["collision"]));
    }
    else
    {
        table = global["CollisionBoxPlayer"];
        if(!table.isNil())
        {
            luabridge::LuaRef size = table["size"];
            entity->addComponent(new CollisionBoxPlayer(sf::Vector2f(size[1].cast<unsigned int>(), size[2].cast<unsigned int>()), table["collision"]));
        }
    }

    table = global["Move"];
    if(!table.isNil())
    {
        entity->addComponent(new Move(table["speed"].cast<unsigned int>()));
    }

    table = global["Health"];
    if(!table.isNil())
    {
        entity->addComponent(new Health(table["health"].cast<unsigned int>()));
    }

    if(!global["PlayerControl"].isNil())
    {
        entity->addComponent(new PlayerControl);
    }

    table = global["Script"];
    if(!table.isNil())
    {
        Script* script = new Script((luabridge::LuaRef)table["receive"]);
        luabridge::LuaRef states = table["states"];
        if(!states.isNil())
        {
            for(const std::string& stateName : lua_getTableKeys(L, name + ".Script.states"))
            {
                luabridge::LuaRef state = states[stateName];
                script->addState(stateName, state["enter"], state["update"]);
            }
        }
        entity->addComponent(script);
    }



    if(!global["Spawner"].isNil())
    {
        entity->addComponent(new Spawner);
    }

    table = global["Timer"];
    if(!table.isNil())
    {
        entity->addComponent(new Timer);
    }

    luabridge::LuaRef init = global["init"];

    m_names.push_back(name);
    m_templates.push_back(entity);
    m_inits.push_back(global["init"]);
}

Entity* EntityFactory::createEntity(const std::string& name, const sf::Vector2f& pos)
{
    int index = -1;
    for(unsigned int i = 0; i != m_names.size(); ++i)
    {
        if(m_names[i] == name)
        {
            index = i;
            break;
        }
    }

    if(index == -1)
    {
        loadEntity(name);
        index = m_names.size() - 1;
    }

    Entity* entity = m_templates[index]->getCopy(pos);
    entity->init();

    if(!m_inits[index].isNil())
    {
        m_inits[index](entity);
    }

    return entity;
}
