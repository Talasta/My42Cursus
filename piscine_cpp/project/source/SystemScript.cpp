#include "SystemScript.hpp"
#include "Entity.hpp"


void ScriptSystem::update()
{
    for(Script* script : m_activeScripts)
    {
        script->update();
    }
}

void ScriptSystem::add(Entity* entity)
{
    Script* script = entity->getComponent<Script>();
    if(script)
    {
        std::vector<Script*>& scriptsList = script->isActive() ? m_activeScripts : m_idleScripts;
        scriptsList.push_back(script);
    }
}

void ScriptSystem::remove(Entity* entity)
{
    Script* script = entity->getComponent<Script>();
    if(script)
    {
        std::vector<Script*>& scriptsList = script->isActive() ? m_activeScripts : m_idleScripts;

        for(unsigned int i = 0; i != scriptsList.size(); ++i)
        {
            if(scriptsList[i] == script)
            {
                scriptsList.erase(scriptsList.begin() + i);
                break;
            }
        }
    }
}

void ScriptSystem::receive(const Message& msg)
{
    Script* script = (Script*)msg.number;
    std::vector<Script*>* scriptsList = script->isActive() ? &m_idleScripts : &m_activeScripts;

    for(unsigned int i = 0; i != scriptsList->size(); ++i)
    {
        if(script == (*scriptsList)[i])
        {
            scriptsList->erase(scriptsList->begin() + i);
            scriptsList = (scriptsList == &m_activeScripts) ? &m_idleScripts : &m_activeScripts;
            scriptsList->push_back(script);

            break;
        }
    }
}
