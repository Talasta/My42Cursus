#ifndef COMPONENTRENDER_HPP
#define COMPONENTRENDER_HPP

#include "Component.hpp"

#include <string>

class	ComponentRender : public Component
{
public:

	enum 	Layer
	{
		Background = 0,		// keep first initialized to zero for proper count
		Enemy,
		Player,
		Bullet,
		EnemyBullet,
		MenuTitle,
		MenuChoice,
		COUNT_LAYER				// keep it last
	};

	static const Component::Type	s_type = Component::Render;

	ComponentRender(const char* = " ", Layer = Background);
	virtual ~ComponentRender();

	const char*			getRepr() const ;
	void				setRepr(const char*);

	Layer				getLayer() const ;
	void 				setLayer(Layer);

private:
	std::string				m_repr;
	Layer					m_layer;

	char _pad[4];

	ComponentRender(const ComponentRender&);
	ComponentRender& operator=(const ComponentRender&);
};

#endif
