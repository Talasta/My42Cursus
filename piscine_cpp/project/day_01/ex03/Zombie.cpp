#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) {
	std::string names[] = {"Maxime", "Franck", "Jonas", "Tommy", "Magalie", \
			"Polo", "Tristouille", "Baptiste", "Marie", "Jeanne"};
	this->_name = names[std::rand()%10];
	std::cout << "Zombie Constructed" << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << "Zombie Destructed" << std::endl;
}

void 		Zombie::announce(void) {
	std::cout << "<" << this->_name << " (zombie)> Braiiiiiiinnnssss...";
	std::cout << std::endl;
}

void 		Zombie::setName(std::string name) { this->_name = name; }
std::string	Zombie::getName(void) { return this->_name; }
