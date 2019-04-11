#include <ComponentCollisionBox.hpp>

ComponentCollisionBox::ComponentCollisionBox(const Vector2f& box) :
	Component(s_type),
	m_box(Vector2f(box.x / 2.f, box.y / 2.f))
{
}

ComponentCollisionBox::~ComponentCollisionBox()
{
}

const Vector2f&		ComponentCollisionBox::getCollisionBox() const
{
	return m_box;
}
