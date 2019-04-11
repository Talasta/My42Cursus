#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include "Zombie.hpp"
# include <iostream>

class ZombieEvent {

public:

	ZombieEvent(void);
	~ZombieEvent(void);

	Zombie* 	newZombie(std::string);
	void 		randomChump(void);

	void 		setZombieType(std::string);
	std::string	getZombieType(void);

private:
	std::string _type;

};

#endif
