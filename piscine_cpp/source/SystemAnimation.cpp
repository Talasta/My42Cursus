#include "SystemAnimation.hpp"


void AnimationSystem::update()
{
    for(Animation* animation : m_animations)
    {
        animation->update();
    }
}

void AnimationSystem::add(Entity* entity)
{
    Animation* animation = entity->getComponent<Animation>();
    if(animation)
    {
        m_animations.push_back(animation);
    }
}

void AnimationSystem::remove(Entity* entity)
{
    Animation* animation = entity->getComponent<Animation>();

    if(animation)
    {
        for(unsigned int i = 0; i != m_animations.size(); ++i)
        {
            if(animation == m_animations[i])
            {
                m_animations.erase(m_animations.begin() + i);
                break;
            }
        }
    }
}
