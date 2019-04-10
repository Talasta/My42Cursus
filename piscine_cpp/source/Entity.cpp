#include "Entity.hpp"

#include "EntityFactory.hpp"
#include "Scene.hpp"
#include "EventManager.hpp"
#include "Vars.hpp"

#include "ComponentAnimation.hpp"
#include "ComponentCollisionBox.hpp"
#include "ComponentHealth.hpp"
#include "ComponentMove.hpp"
#include "ComponentScript.hpp"
#include "ComponentText.hpp"
#include "ComponentTextUI.hpp"
#include "ComponentTimer.hpp"


Entity::Entity(const sf::Vector2f& position) : m_pos(position){}

Entity::~Entity()
{
    for(Component* component : m_components)
    {
        delete component;
    }
}

void Entity::init()
{
    for(Component* component : m_components)
    {
        component->init(this);
    }
}

Entity* Entity::getCopy(const sf::Vector2f& pos) const
{
    Entity* copy = new Entity(pos);

    for(Component* component : m_components)
    {
        copy->addComponent(component->getCopy());
    }

    return copy;
}

void Entity::addComponent(Component* component)
{
    m_components.push_back(component);
}

void Entity::receive(const Message& msg)
{
    for(Component* component : m_components)
    {
        component->receive(msg);
    }
}

sf::Vector2f Entity::getPosition() const
{
    return m_pos;
}

void Entity::move(const sf::Vector2f& shift)
{
    m_pos += shift;
}

void Entity::listenToEvent(const std::string& eventName) const
{
    eventManager->listenToEvent(getComponent<Script>(), eventName);
}



void Entity::setAnimation(const std::string& animationName)
{
    getComponent<Animation>()->setAnimation(animationName);
}


void Entity::setBoxSize(const sf::Vector2f& size)
{
    systems[System::physics]->remove(this);
    getComponent<CollisionBox>()->setSize(sf::Vector2u(size.x, size.y));
    systems[System::physics]->add(this);
}

int Entity::getHealth() const
{
    return getComponent<Health>()->getHealth();
}

unsigned int Entity::getBaseHealth() const
{
    return getComponent<Health>()->getBaseHealth();
}

void Entity::setHealth(unsigned int health)
{
    getComponent<Health>()->setHealth(health);
}

sf::Vector2f Entity::getDirection() const
{
    return getComponent<Move>()->getDirection();
}

void Entity::setTransparency(unsigned char alpha)
{
    getComponent<Render>()->setTransparency(alpha);
}

void Entity::setScriptState(const std::string& stateName)
{
    getComponent<Script>()->setState(stateName);
}


void Entity::setTextString(const std::string& content)
{
    sf::Text* text = getComponent<Text>();
    if(!text)
    {
        text = getComponent<TextUI>();
        text->setString(content);
    }
    else
    {
        text->move(text->getGlobalBounds().width / 2, text->getGlobalBounds().height);
        text->setString(content);
        text->move(- text->getGlobalBounds().width / 2, - text->getGlobalBounds().height);
    }
}

void Entity::setTextColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    sf::Text* text = getComponent<Text>();
    if(!text)
    {
        text = getComponent<TextUI>();
    }
    text->setColor(sf::Color(r,g,b,a));
}


float Entity::getTimerSecondsElapsed() const
{
    return getComponent<Timer>()->getSecondsElapsed();
}

void Entity::restartTimer()
{
    getComponent<Timer>()->restart();
}
