#include "ComponentCollisionBox.hpp"

#include "Entity.hpp"


const Component::Type CollisionBox::s_type = Component::CCollisionBox;

CollisionBox::CollisionBox(const sf::Vector2f& size, const luabridge::LuaRef& collision) : Component(Component::CCollisionBox),
                                                                                           m_boxRect(-size.x/2,-size.y, size.x, size.y),
                                                                                           m_reactsOnCollision(!collision.isNil()),
                                                                                           m_collision(collision)
{

}

void CollisionBox::init(Entity* owner)
{
    m_owner = owner;

    m_boxRect.left += owner->getPosition().x;
    m_boxRect.top += owner->getPosition().y;
}

Component* CollisionBox::getCopy() const
{
    return new CollisionBox(sf::Vector2f(m_boxRect.width, m_boxRect.height), m_collision);
}

void CollisionBox::receive(const Message& msg)
{
    if(msg.type == Message::MMove)
    {
        m_boxRect.left += msg.vector.x;
        m_boxRect.top += msg.vector.y;
    }
}

const sf::FloatRect& CollisionBox::getBoxRect() const
{
    return m_boxRect;
}

Entity* CollisionBox::getOwner() const
{
    return m_owner;
}

bool CollisionBox::reactsOnCollision() const
{
    return m_reactsOnCollision;
}

void CollisionBox::collision(Entity* collided)
{
    m_collision(m_owner, collided);
}

void CollisionBox::setSize(const sf::Vector2u& size)
{
    m_boxRect.left += m_boxRect.width / 2;
    m_boxRect.top += m_boxRect.height;

    m_boxRect.width = size.x;
    m_boxRect.height = size.y;

    m_boxRect.left -= m_boxRect.width / 2;
    m_boxRect.top -= m_boxRect.height;
}
