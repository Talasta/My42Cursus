#ifndef ENTITYFACTORY_HPP
#define ENTITYFACTORY_HPP

#include "Entity.hpp"

//Entity Factory
class	EF
{
public:

	static unsigned int s_score;

	enum Who
	{
		Player = 0,
		Bullet,
		Enemy,
		Background,
		GameOver,
		GameOverSel,
		EnemyBullet,
		COUNT
	};

	static Entity*		build(const Vector2f& position, Who);


	static const char*	s_str;

private:

	EF();
	EF(const EF&);
	EF& operator=(const EF&);
	~EF();
};

#endif
