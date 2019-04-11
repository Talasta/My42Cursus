#include "SystemTimer.hpp"


void TimerSystem::update()
{

}

void TimerSystem::add(Entity* entity)
{
    Timer* timer = entity->getComponent<Timer>();
    if(timer)
    {
        m_timers.push_back(timer);
    }
}

void TimerSystem::remove(Entity* entity)
{
    Timer* timer = entity->getComponent<Timer>();
    if(timer)
    {
        for(unsigned int i = 0; i != m_timers.size(); ++i)
        {
            if(timer == m_timers[i])
            {
                m_timers.erase(m_timers.begin() + i);
                break;
            }
        }
    }
}

void TimerSystem::receive(const Message& msg)
{
    for(Timer* timer : m_timers)
    {
        timer->resume(msg.number);
    }
}
