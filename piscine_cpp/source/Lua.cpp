#include "Lua.hpp"

#include "Vars.hpp"

#include <iostream>


std::vector<std::string> lua_getTableKeys(lua_State* L, const std::string& tablePath)
{
    lua_pop(L, lua_gettop(L));

    bool global = true;

    std::string temp = "";

    for(unsigned int i = 0; i != tablePath.size(); ++i)
    {
        if(tablePath[i] != '.')
        {
            temp += tablePath[i];
        }
        else
        {
            if(global)
            {
                global = false;
                lua_getglobal(L, temp.c_str());
            }
            else
            {
                lua_getfield(L, -1, temp.c_str());
            }
            temp = "";
        }
    }

    lua_getfield(L, -1, temp.c_str());

    std::vector<std::string> keys;

    for(lua_pushnil(L); lua_next(L, -2); lua_pop(L, 1))
    {
        keys.push_back(lua_tostring(L, -2));
    }

    return keys;
}

void print(const std::string& content)
{
    std::cout << content << std::endl;
}

void playSound(const std::string& soundName)
{
    audioManager->playSound(soundName);
}

Entity* create(const std::string& entityName, const sf::Vector2f& entityPos)
{
    Entity* entity = entityFactory->createEntity(entityName, entityPos);

    currentScene->add(entity);

    return entity;
}

void kill(Entity* entity)
{
    currentScene->remove(entity);
}

void triggerEvent(const std::string& eventName, Message& msg)
{
    eventManager->triggerEvent(eventName, msg);
}
