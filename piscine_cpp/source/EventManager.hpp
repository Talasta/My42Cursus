#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

#include "Event.hpp"

class EventManager{

public:

    EventManager();

    void createEvent(const std::string& eventName);
    void listenToEvent(MessageHandler* listener, const std::string& eventName);
    void triggerEvent(const std::string& eventName, Message& msg);


private:

    std::vector<Event> m_events;

};

#endif
