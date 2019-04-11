#include <ComponentMove.hpp>

ComponentMove::ComponentMove() : Component(s_type)
{
}

ComponentMove::~ComponentMove()
{
}

const Vector2f&		ComponentMove::getMove() const
{
	return m_move;
}

void				ComponentMove::setMove(const Vector2f& move)
{
	m_move = move;
}
