#ifndef COMPONENTMOVE_HPP
#define COMPONENTMOVE_HPP

#include "Component.hpp"
#include "Vector2.hpp"

class	ComponentMove : public Component
{
public:

	static const Component::Type	s_type = Component::Move;

	ComponentMove();
	virtual ~ComponentMove();

	const Vector2f&		getMove() const;
	void				setMove(const Vector2f&);

private:

	ComponentMove(const ComponentMove&);
	ComponentMove& operator=(const ComponentMove&);

	Vector2f	m_move;		//	speed in squares per second
};

#endif
