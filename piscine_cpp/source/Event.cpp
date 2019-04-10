#include "Event.hpp"


Event::Event(const std::string& eventName) : name(eventName)
{

}

void Event::addListener(MessageHandler* listener)
{
    m_listeners.push_back(listener);
}

void Event::trigger(const Message& msg)
{
    for(MessageHandler* listener : m_listeners)
    {
        listener->receive(msg);
    }
}
