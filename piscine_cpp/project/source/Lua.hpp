#ifndef LUA_HPP
#define LUA_HPP

#include "Entity.hpp"

#include <lua.hpp>


std::vector<std::string> lua_getTableKeys(lua_State* L, const std::string& tablePath);

void print(const std::string& content);

void playSound(const std::string& soundName);

Entity* create(const std::string& entityName, const sf::Vector2f& entityPos);
void kill(Entity* entity);

void triggerEvent(const std::string& eventName, Message& msg);


#endif
