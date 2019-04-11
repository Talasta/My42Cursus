#include "HumanA.hpp"

HumanA::HumanA(std::string str, Weapon& weapon) : _name(str), _weapon(weapon) {
	// std::cout << "Constructed" << std::endl;
}

HumanA::~HumanA(void) {
	// std::cout << "Destructed" << std::endl;
}

void 		HumanA::attack(void) {
	std::cout << this->getName() << " attacks with his " << this->getWeapon().getType();
	std::cout << std::endl;
}

std::string	HumanA::getName(void) { return this->_name; }
Weapon&		HumanA::getWeapon(void) { return this->_weapon; }
