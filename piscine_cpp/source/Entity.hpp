#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Component.hpp"
#include "MessageHandler.hpp"

#include <string>
#include <vector>


class Entity : public MessageHandler{

public:

    Entity(const sf::Vector2f& position);
    ~Entity();

    void init();
    Entity* getCopy(const sf::Vector2f& pos) const;
    virtual void receive(const Message& msg);


    void addComponent(Component* component);

    template<typename T>
    T* getComponent() const
    {
        for(Component* component : m_components)
        {
            if(component->type() == T::s_type)
            {
                return dynamic_cast<T*>(component);
            }
        }
        return nullptr;
    }

    sf::Vector2f getPosition() const;
    void move(const sf::Vector2f& shift);

    void listenToEvent(const std::string& eventName) const;


    void setAnimation(const std::string& animationName);

    void setBoxSize(const sf::Vector2f& size);

    int getHealth() const;
    unsigned int getBaseHealth() const;
    void setHealth(unsigned int health);

    sf::Vector2f getDirection() const;

    void setTransparency(unsigned char alpha);

    void setScriptState(const std::string& stateName);

    void setTextString(const std::string& content);
    void setTextColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

    float getTimerSecondsElapsed() const;
    void restartTimer();

private:

    std::vector<Component*> m_components;

    sf::Vector2f m_pos;

};

#endif
