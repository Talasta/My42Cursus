#ifndef COMPONENTENEMY_HPP
#define COMPONENTENEMY_HPP

#include "Component.hpp"

class	ComponentEnemy : public Component
{
public:

	enum 	Type
	{
		Enemy1 = 0,		// keep first initialized to zero for proper count
		Enemy2,		// keep first initialized to zero for proper count
		COUNT_ENEMY		// keep it last
	};

	static const Component::Type	s_type = Component::Enemy;

	ComponentEnemy();
	ComponentEnemy(Type, unsigned int life = 10);
	virtual ~ComponentEnemy();

	Type				getType() const ;
	unsigned int		getLife() const ;
	void				setLife(unsigned int);

	float					bulletTime;

private:
	const Type				m_type;
	unsigned int			m_life;
	
	char _pad[4];

	ComponentEnemy(const ComponentEnemy&);
	ComponentEnemy& operator=(const ComponentEnemy&);
};

#endif
