#include "ComponentMove.hpp"
#include "Entity.hpp"


const Component::Type Move::s_type = Component::CMove;


Move::Move(float speed) : Component(Component::CMove), m_speed(speed)
{
    m_move.x = m_speed;
}

void Move::init(Entity* owner)
{
    m_owner = owner;
}

Component* Move::getCopy() const
{
    return new Move(m_speed);
}

void Move::receive(const Message& msg)
{
    if(msg.type == Message::MMove)
    {
        m_owner->move(msg.vector);
    }
    else if(msg.type == Message::MSetMove)
    {
        m_moving = msg.vector.x != 0 || msg.vector.y != 0;
        if(m_moving)
        {
            m_move = msg.vector * m_speed;
            if(m_move.x != 0 && m_move.y != 0)
            {
                m_move /= 1.4f;
            }
        }
    }
}

Entity* Move::getOwner() const
{
    return m_owner;
}

bool Move::isMoving() const
{
    return m_moving;
}

const sf::Vector2f& Move::getMove() const
{
    return m_move;
}

sf::Vector2f Move::getDirection() const
{
    if(m_move.x != 0 && m_move.y != 0)
    {
        return sf::Vector2f(m_move.x * 1.4f / m_speed, 0);
    }
    return m_move / m_speed;
}
