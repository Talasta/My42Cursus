#include "ComponentAI.hpp"

#include "Vars.hpp"

#include <cmath>


const Component::Type AI::s_type = Component::CAI;

AI::AI(unsigned int attackDistance, const luabridge::LuaRef& attack) : Component(Component::CAI), m_attackDistance(attackDistance), m_attack(attack)
{

}

Component* AI::getCopy() const
{
    return new AI(m_attackDistance, m_attack);
}

void AI::init(Entity* owner)
{
    m_owner = owner;
}

void AI::receive(const Message& msg)
{
    if(msg.type == Message::MMove)
    {
        m_path->travelledDistance += std::abs(msg.vector.x) + std::abs(msg.vector.y);
    }
    else if(msg.type == Message::MHit)
    {
        Message message(Message::MEventCallback);
        eventManager->triggerEvent("enemyHit", message);
    }
}

unsigned int AI::getAttackDistance() const
{
    return m_attackDistance;
}

bool AI::getState() const
{
    return m_state;
}

Path* AI::getPath()
{
    return m_path;
}

void AI::setPath(Path* path)
{
    m_path = path;
}

void AI::setState(bool state)
{
    m_state = state;
}

void AI::attack(Entity* target)
{
    m_attack(m_owner, target);
}
