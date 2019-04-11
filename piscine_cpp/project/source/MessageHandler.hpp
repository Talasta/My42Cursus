#ifndef MESSAGEHANDLER_HPP
#define MESSAGEHANDLER_HPP

#include "Message.hpp"

class MessageHandler{

public:

    virtual void receive(const Message& msg) = 0;
};

#endif
