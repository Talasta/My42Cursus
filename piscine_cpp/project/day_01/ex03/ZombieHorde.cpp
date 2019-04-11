#include "ZombieHorde.hpp"
#include <iostream>

ZombieHorde::ZombieHorde(size_t n) : _horde(new Zombie[n]), _n(n) {
	std::cout << "ZombieHorde Constructed" << std::endl;
}

ZombieHorde::~ZombieHorde(void) {
	delete [] this->getHorde();
	std::cout << "ZombieHorde Destructed" << std::endl;
}

void 	ZombieHorde::announce(void) {
	for (int i = 0; i < (int)this->getSize(); i++) {
		this->getHorde()[i].announce();
	}
}

int		ZombieHorde::getSize(void) { return this->_n; }
Zombie*	ZombieHorde::getHorde(void) { return this->_horde; }
