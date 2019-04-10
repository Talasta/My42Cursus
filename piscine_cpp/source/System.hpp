#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "MessageHandler.hpp"
#include "Entity.hpp"


class System : public MessageHandler{

public:

    enum { ai = 0, animation, physics, playerControl, render, script, spawner, timer, ui };

    virtual void update() = 0;

    virtual void add(Entity* entity) = 0;
    virtual void remove(Entity* entity) = 0;

    virtual void receive(const Message& msg){}

};

#endif
