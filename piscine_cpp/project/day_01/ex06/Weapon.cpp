#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {
	// std::cout << "Constructed" << std::endl;
}

Weapon::~Weapon(void) {
	// std::cout << "Destructed" << std::endl;
}

void 	Weapon::setType (std::string type) {
	this->_type = type;
}

const std::string& 	Weapon::getType ( void ) {
	const std::string& ref = this->_type;
	return ref;
}
