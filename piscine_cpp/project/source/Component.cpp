#include "Component.hpp"


Component::Component(Type componentType) : m_type(componentType)
{

}

Component::~Component()
{

}

void Component::init(Entity* owner)
{

}

void Component::receive(const Message& msg)
{

}

Component::Type Component::type() const
{
    return m_type;
}
