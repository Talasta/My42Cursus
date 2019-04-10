#include "ComponentCollisionBoxPlayer.hpp"

#include "Entity.hpp"


const Component::Type CollisionBoxPlayer::s_type = Component::CCollisionBoxPlayer;

CollisionBoxPlayer::CollisionBoxPlayer(const sf::Vector2f& size, const luabridge::LuaRef& collision) : Component(Component::CCollisionBoxPlayer),
                                                                                                                    m_boxRect(-size.x/2,-size.y, size.x, size.y),
                                                                                                                    m_collision(collision)
{

}

void CollisionBoxPlayer::init(Entity* owner)
{
    m_owner = owner;

    m_boxRect.left += owner->getPosition().x;
    m_boxRect.top += owner->getPosition().y;
}

Component* CollisionBoxPlayer::getCopy() const
{
    return new CollisionBoxPlayer(sf::Vector2f(m_boxRect.width, m_boxRect.height), m_collision);
}

const sf::FloatRect& CollisionBoxPlayer::getBoxRect() const
{
    return m_boxRect;
}

void CollisionBoxPlayer::collision(Entity* player)
{
    m_collision(m_owner, player);
}
