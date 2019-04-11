#ifndef COMPONENTPLAYER_HPP
#define COMPONENTPLAYER_HPP

#include "Component.hpp"

class	ComponentPlayer : public Component
{
public:

	static const Component::Type	s_type = Component::Player;

	ComponentPlayer();
	virtual ~ComponentPlayer();

private:

	ComponentPlayer(const ComponentPlayer&);
	ComponentPlayer& operator=(const ComponentPlayer&);
};

#endif
