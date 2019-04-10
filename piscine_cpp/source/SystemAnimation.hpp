#ifndef SYSTEMANIMATION_HPP
#define SYSTEMANIMATION_HPP

#include "System.hpp"
#include "ComponentAnimation.hpp"

class AnimationSystem : public System{

public:

    virtual void update();

    virtual void add(Entity* entity);
    virtual void remove(Entity* entity);


private:

    std::vector<Animation*> m_animations;

};

#endif
