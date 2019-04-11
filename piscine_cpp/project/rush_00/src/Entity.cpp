#include "Entity.hpp"

Entity::Entity(const Vector2f& position) : m_pos(position)
{
}

Entity::~Entity()
{
	for (Component** c = m_components; *c; ++c)
		delete *c;
}

void		Entity::addComponent(Component* c)
{
	m_components.push_back(c);
}

const Vector2f& 	Entity::getPosition() const
{
	return m_pos;
}

void				Entity::setPosition(const Vector2f& pos)
{
	m_pos = pos;
}
