#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include "Zombie.hpp"

class ZombieHorde {

public:

	ZombieHorde( size_t );
	~ZombieHorde( void );
	void announce( void );

	int			getSize(void);
	Zombie*		getHorde(void);

private:
	Zombie* 	_horde;
	size_t 		_n;

};

#endif
