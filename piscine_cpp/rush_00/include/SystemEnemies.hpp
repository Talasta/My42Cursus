#ifndef SYSTEMENEMIES_HPP
#define SYSTEMENEMIES_HPP

#include <ncurses.h>

#include "System.hpp"
#include "Array.hpp"
#include "ComponentEnemy.hpp"

class	SystemEnemies : public System
{
public:

	SystemEnemies();
	virtual ~SystemEnemies();

	virtual int		init(Scene*);
	virtual int		update(float elapsedTime);

	virtual void	addEntity(Entity*);
	virtual void	removeEntity(Entity*);

private:

	SystemEnemies(const SystemEnemies&);
	SystemEnemies& operator=(const SystemEnemies&);

	Scene*											m_scene;
	Entity* 										m_player;
	Array<Entity*, ENTITIES_ARRAYS_LEN>				m_entities;
	Array<ComponentEnemy*, ENTITIES_ARRAYS_LEN>		m_enemies;
};


#endif
