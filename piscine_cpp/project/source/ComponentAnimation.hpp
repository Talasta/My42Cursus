#ifndef COMPONENTANIMATION_HPP
#define COMPONENTANIMATION_HPP

#include "Component.hpp"

#include "ComponentRender.hpp"

#include <SFML/Graphics/Rect.hpp>


struct animation{

    animation(const std::string& Name, unsigned int FrameCount, const sf::Rect<unsigned int>& TexCoords) : name(Name), frameCount(FrameCount), texCoords(TexCoords){}

    std::string name;
    unsigned int frameCount;
    sf::Rect<unsigned int> texCoords;
};

class Animation : public Component{

public:

    static const Component::Type s_type;
    virtual Component* getCopy() const;

    Animation(float FrameTime);
    virtual void init(Entity* owner);

    virtual void receive(const Message& msg);


    void addAnimation(const std::string& name, unsigned int frameCount, const sf::Rect<unsigned int>& texCoords);
    void update();


    void setAnimation(const std::string& animationName);


private:

    Render* m_render;

    std::vector<animation> m_animations;

    float m_frameTime;

    unsigned char m_direction = 0;

    float m_timer = 0;
    unsigned char m_currentAnimation = 0;
    unsigned char m_currentFrame = 0;

};

#endif
