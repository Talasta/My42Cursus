#include "HumanB.hpp"

HumanB::HumanB(std::string str) : _name(str) {
	// std::cout << "Constructed" << std::endl;
}

HumanB::~HumanB(void) {
	// std::cout << "Destructed" << std::endl;
}

void 		HumanB::attack(void) {
	std::cout << this->_name
			<< " attacks with his "
			<< this->_weapon->getType()
			<< std::endl;
}

std::string	HumanB::getName(void) { return this->_name; }
Weapon*		HumanB::getWeapon(void) { return this->_weapon; }
void 		HumanB::setWeapon(Weapon& weapon) { this->_weapon = &weapon; }
