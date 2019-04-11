#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "Entity.hpp"

class Scene;

class	System
{
public:

/*	This enum defines the order in which systems are updated */
	enum	Type
	{
		PlayerInput = 0,	// keep first initialized to zero for proper count
		Enemies,
		Physics,
		Render,
		COUNT				// keep it last
	};

	virtual ~System();

/*	This function shall return 0 on success, or -1 on error */
	virtual int		init(Scene*) = 0;

/*	This function shall return > 0 while the loop shall continue,
	0 when it shall stop without error
	or < 0 to stop with an error	*/
	virtual int		update(float elapsedTime) = 0;

	virtual void	addEntity(Entity*) = 0;
	virtual void	removeEntity(Entity*) = 0;

protected:

	System();

private:

	System(const System&);
	System&	operator=(const System&);
};

#endif
