#ifndef COMPONENTTIMER_HPP
#define COMPONENTTIMER_HPP

#include "Component.hpp"

#include <ctime>


class Timer : public Component{

public:

    static const Component::Type s_type;
    virtual Component* getCopy() const;

    Timer();

    void resume(unsigned int timeElapsed);

    void restart();
    float getSecondsElapsed() const;


private:

    unsigned int m_time = std::clock();
};


#endif
