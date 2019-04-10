#ifndef COMPONENTCOLLISIONBOX_HPP
#define COMPONENTCOLLISIONBOX_HPP

#include "Component.hpp"
#include "Vector2.hpp"

class	ComponentCollisionBox : public Component
{
public:

	static const Component::Type	s_type = Component::CollisionBox;

	ComponentCollisionBox(const Vector2f& box);
	virtual ~ComponentCollisionBox();

	const Vector2f&		getCollisionBox() const;

private:

	ComponentCollisionBox(const ComponentCollisionBox&);
	ComponentCollisionBox& operator=(const ComponentCollisionBox&);

	Vector2f	m_box;
};

#endif
