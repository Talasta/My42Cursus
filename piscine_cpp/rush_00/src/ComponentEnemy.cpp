#include <ComponentEnemy.hpp>
#include <game.hpp>
#include <cstdlib>

ComponentEnemy::ComponentEnemy() : Component(s_type), bulletTime(INIT_ENEMY_BULLET_TIME), m_type(ComponentEnemy::Enemy1), m_life(1)
{
}

ComponentEnemy::ComponentEnemy(Type type, unsigned int life) : Component(s_type), bulletTime(INIT_ENEMY_BULLET_TIME), m_type(type), m_life(life)
{
}

ComponentEnemy::~ComponentEnemy()
{
}

ComponentEnemy::Type    ComponentEnemy::getType() const
{
    return m_type;
}

unsigned int            ComponentEnemy::getLife() const
{
    return m_life;
}
void                    ComponentEnemy::setLife(unsigned int life)
{
    m_life = life;
}
