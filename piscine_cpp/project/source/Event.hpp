#ifndef EVENT_HPP
#define EVENT_HPP

#include "ComponentScript.hpp"

#include <string>
#include <vector>

class Event{

public:

    Event(const std::string& eventName);

    std::string name;

    void addListener(MessageHandler* listener);
    void trigger(const Message& msg);


private:

    std::vector<MessageHandler*> m_listeners;


};

#endif
