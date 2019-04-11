#include "ComponentHealth.hpp"

#include "ComponentRender.hpp"
#include "ComponentText.hpp"

#include "Vars.hpp"


const Component::Type Health::s_type = Component::CHealth;

Health::Health(unsigned int health) : Component(Component::CHealth), m_health(health), m_baseHealth(health)
{

}

void Health::init(Entity* owner)
{
    m_owner = owner;
}

Component* Health::getCopy() const
{
    return new Health(m_baseHealth);
}

void Health::receive(const Message& msg)
{
    if(msg.type == Message::MHit)
    {
        m_health -= msg.number;

        if(m_health <= 0)
        {
            currentScene->remove(m_owner);
        }

        std::stringstream number;
        number << (msg.number);

        Entity* entity = entityFactory->createEntity("flyingText", m_owner->getPosition() - sf::Vector2f(0, m_owner->getComponent<Render>()->getApparentSize().y));
        entity->setTextString("-" + number.str());
        currentScene->add(entity);
    }
}

int Health::getHealth() const
{
    return m_health;
}

unsigned int Health::getBaseHealth() const
{
    return m_baseHealth;
}

void Health::setHealth(unsigned int health)
{
    m_health = health > m_baseHealth ? m_baseHealth : health;
}
