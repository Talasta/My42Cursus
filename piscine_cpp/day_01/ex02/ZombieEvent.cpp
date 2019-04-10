#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void) {
	std::cout << "ZombieEvent Constructed" << std::endl;
}

ZombieEvent::~ZombieEvent(void) {
	std::cout << "ZombieEvent Destructed" << std::endl;
}

Zombie* 	ZombieEvent::newZombie(std::string name) {
	return new Zombie(name, this->_type);
}

void 		ZombieEvent::randomChump(void) {
	std::string names[] = {"Maxime", "Franck", "Jonas", "Tommy", "Magalie", \
			"Polo", "Tristouille", "Baptiste", "Marie", "Jeanne"};
	std::string name = names[std::rand()%10];
	Zombie 	zz = Zombie(name, this->_type);
	zz.announce();
}

std::string ZombieEvent::getZombieType(void) { return this->_type; }
void 		ZombieEvent::setZombieType(std::string type) { this->_type = type; }
