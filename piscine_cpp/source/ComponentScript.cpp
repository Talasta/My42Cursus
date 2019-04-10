#include "ComponentScript.hpp"

#include "Vars.hpp"


const Component::Type Script::s_type = Component::CScript;

Script::Script(const luabridge::LuaRef& Receive) : Component(Component::CScript), m_receive(Receive), m_receives(!Receive.isNil())
{

}

void Script::init(Entity* owner)
{
    m_owner = owner;
}

Component* Script::getCopy() const
{
    Script* script = new Script(m_receive);
    for(const state& State : m_states)
    {
        script->addState(State.name, State.enter, State.update);
    }

    return script;
}

void Script::receive(const Message& msg)
{
    if(m_receives && msg.type < 5)
    {
        m_receive(m_owner, &msg);
    }
}

void Script::addState(const std::string& stateName, const luabridge::LuaRef& enter, const luabridge::LuaRef& update)
{
    m_states.push_back(state(stateName, enter, update));
}

void Script::setState(const std::string& stateName)
{
    bool wasIdle = m_currentState == -1;

    m_currentState = -1;

    for(unsigned int i = 0; i != m_states.size(); ++i)
    {
        if(m_states[i].name == stateName)
        {
            m_currentState = i;
            if(!m_states[i].enter.isNil())
            {
                m_states[i].enter(m_owner);
            }
            break;
        }
    }

    if(m_currentState == -1 || wasIdle)
    {
        Message msg;
        msg.number = (unsigned int)this;
        systems[System::script]->receive(msg);
    }
}

void Script::update()
{
    m_states[m_currentState].update(m_owner);
}

bool Script::isActive()
{
    return m_currentState != -1;
}
