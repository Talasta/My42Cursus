#ifndef SYSTEMTIMER_HPP
#define SYSTEMTIMER_HPP

#include "System.hpp"

#include "ComponentTimer.hpp"


class TimerSystem : public System{

public:

    virtual void update();

    virtual void add(Entity* entity);
    virtual void remove(Entity* entity);

    virtual void receive(const Message& msg);


private:

    std::vector<Timer*> m_timers;
};

#endif
