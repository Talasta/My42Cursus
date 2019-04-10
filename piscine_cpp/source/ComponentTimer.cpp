#include "ComponentTimer.hpp"

#include "Vars.hpp"


const Component::Type Timer::s_type = Component::CTimer;

Timer::Timer() : Component(Component::CTimer)
{

}

Component* Timer::getCopy() const
{
    return new Timer;
}

void Timer::resume(unsigned int timeElapsed)
{
    m_time += timeElapsed;
}

void Timer::restart()
{
    m_time = std::clock();
}

float Timer::getSecondsElapsed() const
{
    return float(std::clock() - m_time) / CLOCKS_PER_SEC;
}
