#include "ComponentAnimation.hpp"

#include "Entity.hpp"

#include "Vars.hpp"


const Component::Type Animation::s_type = Component::CAnimation;

Animation::Animation(float frameTime) : Component(Component::CAnimation), m_frameTime(frameTime){

}

Component* Animation::getCopy() const
{
    Animation* copy = new Animation(m_frameTime);

    for(const animation& anim : m_animations)
    {
        copy->addAnimation(anim.name, anim.frameCount, anim.texCoords);
    }

    return copy;
}

void Animation::init(Entity* owner)
{
    m_render = owner->getComponent<Render>();;
}

void Animation::receive(const Message& msg)
{
    if(msg.type == Message::MSetMove)
    {
        sf::Vector2f shift(msg.vector);
        if(shift.x != 0 || shift.y != 0)
        {
            m_direction = shift.x != 0 ? shift.x < 0 : 3 - (shift.y < 0);
            if(m_animations[m_currentAnimation].name != "moving")
            {
                setAnimation("moving");
            }
        }
        else if(m_animations[m_currentAnimation].name != "idle")
        {
            setAnimation("idle");
        }
    }
}

void Animation::addAnimation(const std::string& name, unsigned int frameCount, const sf::Rect<unsigned int>& texCoords)
{
    m_animations.emplace_back(name, frameCount, texCoords);
}


void Animation::update()
{
    m_timer += dt;

    if(m_timer > m_frameTime)
    {
        m_timer = 0;
        if(++m_currentFrame == m_animations[m_currentAnimation].frameCount)
        {
            m_currentFrame = 0;
        }

        sf::Rect<unsigned int> texCoords = m_animations[m_currentAnimation].texCoords;

        m_render->setTexCoords(sf::Rect<unsigned int>(texCoords.left + texCoords.width * m_currentFrame,
                                                      texCoords.top + texCoords.height * m_direction,
                                                      texCoords.width,
                                                      texCoords.height));
    }
}

void Animation::setAnimation(const std::string& animationName)
{
    for(unsigned int i = 0; i != m_animations.size(); ++i)
    {
        if(animationName == m_animations[i].name)
        {
            m_currentAnimation = i;
            break;
        }
    }

    m_currentFrame = 0;
}
