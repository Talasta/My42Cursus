#ifndef SCENE_HPP
#define SCENE_HPP

#include "Entity.hpp"
#include "Array.hpp"
#include "System.hpp"

#include <ctime>

class	Scene
{
public:

	Scene();
	~Scene();

	int		init();

	void	addEntity(Entity*);
	void	removeEntity(Entity*);

	int		update();
	void	updateEntities();

	void	wipe();

private:

	Scene(const Scene&);
	Scene& operator=(const Scene&);

	Array<Entity*, ENTITIES_ARRAYS_LEN>		m_entities;
	Array<Entity*, ENTITIES_ARRAYS_LEN>		m_entitiesToRm;

	System*									m_systems[System::COUNT];

	std::clock_t							m_clock;
	unsigned int							m_entitiesLen;

	char _pad[4];
};

#endif
