#ifndef ENTITYFACTORY_HPP
#define ENTITYFACTORY_HPP

#include "Entity.hpp"

#include <lua.hpp>
#undef cast
#include <LuaBridge.h>


class EntityFactory{

public:

    EntityFactory();
    ~EntityFactory();

    Entity* createEntity(const std::string& name, const sf::Vector2f& pos);

private:

    void loadEntity(const std::string& name);

    lua_State* L;

    std::vector<std::string> m_names;
    std::vector<Entity*> m_templates;
    std::vector<luabridge::LuaRef> m_inits;
};

#endif
