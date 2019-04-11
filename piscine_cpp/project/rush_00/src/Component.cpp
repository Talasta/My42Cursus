#include <Component.hpp>

Component::Component(Type type) : m_type(type)
{
}

Component::~Component()
{
}

Component::Type		Component::getType() const
{
	return m_type;
}
