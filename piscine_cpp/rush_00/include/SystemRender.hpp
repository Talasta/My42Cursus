#ifndef SYSTEMRENDER_HPP
#define SYSTEMRENDER_HPP

#include <ncurses.h>

#include "System.hpp"
#include "Scene.hpp"
#include "Array.hpp"
#include "ComponentRender.hpp"

class	SystemRender : public System
{
public:

	SystemRender();
	virtual ~SystemRender();

	virtual int		init(Scene*);
	virtual int		update(float elapsedTime);

	virtual void	addEntity(Entity*);
	virtual void	removeEntity(Entity*);

private:

	SystemRender(const SystemRender&);
	SystemRender& operator=(const SystemRender&);

	int				backgroundRegenerate();

	int 			updateSizeWindow();
	int 			draw(const Vector2f& , const ComponentRender*) const;

	Scene*											m_scene;
	Array<ComponentRender*, ENTITIES_ARRAYS_LEN>	m_renders;
	Array<Entity*, ENTITIES_ARRAYS_LEN>				m_entities;
	WINDOW 											*m_window;
	Vector2u										m_winsize;
	unsigned int									m_countBackgrounds;
	char	_pad[4];

};

#define MAX_IN_BACKGROUND 100

#endif
