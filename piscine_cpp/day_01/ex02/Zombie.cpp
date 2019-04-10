#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type) : _name(name), _type(type) {
	std::cout << "Zombie Constructed" << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << "Zombie Destructed" << std::endl;
}

void 		Zombie::announce(void) {
	std::cout << "<" << this->getName() << " (" << this->getType();
	std::cout << ")> Braiiiiiiinnnssss..." << std::endl;
}

std::string	Zombie::getName(void) { return this->_name; }
std::string	Zombie::getType(void) { return this->_type; }
