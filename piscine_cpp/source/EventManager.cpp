#include "EventManager.hpp"


EventManager* eventManager;

EventManager::EventManager()
{
    eventManager = this;
}

void EventManager::createEvent(const std::string& eventName)
{
    m_events.emplace_back(eventName);
}

void EventManager::listenToEvent(MessageHandler* listener, const std::string& eventName)
{
    bool found = false;

    for(Event& event : m_events)
    {
        if(event.name == eventName)
        {
            found = true;
            event.addListener(listener);
            break;
        }
    }

    if(!found)
    {
        m_events.emplace_back(eventName);
        m_events[m_events.size() - 1].addListener(listener);
    }
}

void EventManager::triggerEvent(const std::string& eventName, Message& msg)
{
    msg.string = eventName;

    for(unsigned int i = 0; i != m_events.size(); ++i)
    {
        if(m_events[i].name == eventName)
        {
            m_events[i].trigger(msg);
            break;
        }
    }
}
