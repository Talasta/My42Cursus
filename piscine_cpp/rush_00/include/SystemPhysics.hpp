#ifndef SYSTEMPHYSICS_HPP
#define SYSTEMPHYSICS_HPP

#include <ncurses.h>

#include "System.hpp"
#include "Array.hpp"
#include "InfoDisp.hpp"
#include "ComponentMove.hpp"
#include "ComponentCollisionBox.hpp"

class	SystemPhysics : public System
{
public:

	SystemPhysics();
	virtual ~SystemPhysics();

	virtual int		init(Scene*);
	virtual int		update(float elapsedTime);

	virtual void	addEntity(Entity*);
	virtual void	removeEntity(Entity*);

private:

	SystemPhysics(const SystemPhysics&);
	SystemPhysics& operator=(const SystemPhysics&);

	int 	handleCollision(Entity*, Entity*);

	Scene*	m_scene;

	Array<Entity*, ENTITIES_ARRAYS_LEN>						m_entities;
	Array<ComponentMove*, ENTITIES_ARRAYS_LEN>				m_moves;
	Array<ComponentCollisionBox*, ENTITIES_ARRAYS_LEN>		m_boxes;

	InfoDisp												m_infoDisp;
};

#endif
