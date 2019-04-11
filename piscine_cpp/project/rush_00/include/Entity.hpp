#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Component.hpp"
#include "Array.hpp"
#include "Vector2.hpp"

class	Entity
{
public:

	Entity(const Vector2f& position);
	~Entity();

	void					addComponent(Component*);

	template<typename T>
	T*	getComponent() const
	{
		for (Component* const* c = m_components; *c; ++c)
			if ((*c)->getType() == T::s_type)
				return dynamic_cast<T*>(*c);
		return NULL;
	}

	const Vector2f&		getPosition() const;
	void				setPosition(const Vector2f&);

private:

	Entity();
	Entity(const Entity&);
	Entity& operator=(const Entity&);

	Array<Component*, Component::COUNT + 1>		m_components;
	Vector2f									m_pos;
};

#define ENTITIES_ARRAYS_LEN 1000	//	above this limit, behaviour is undefined

#endif
