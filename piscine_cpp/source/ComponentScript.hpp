#ifndef COMPONENTSCRIPT_HPP
#define COMPONENTSCRIPT_HPP

#include "Component.hpp"

#include "lua.hpp"
#undef cast
#include "LuaBridge.h"

struct state{

    state(const std::string& stateName, const luabridge::LuaRef& Enter, const luabridge::LuaRef& Update) : name(stateName), enter(Enter), update(Update){}

    std::string name;
    luabridge::LuaRef enter;
    luabridge::LuaRef update;
};

class Script : public Component{

public:

    static const Component::Type s_type;
    virtual Component* getCopy() const;

    Script(const luabridge::LuaRef& Receive);
    virtual void init(Entity* entity);

    virtual void receive(const Message& msg);

    void addState(const std::string& stateName, const luabridge::LuaRef& enter, const luabridge::LuaRef& update);
    void setState(const std::string& stateName);

    void update();

    bool isActive();



private:

    Entity* m_owner = nullptr;

    luabridge::LuaRef m_receive;
    bool m_receives;

    std::vector<state> m_states;
    signed char m_currentState = -1;


};


#endif
