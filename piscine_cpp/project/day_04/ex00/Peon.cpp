#include "Peon.hpp"

Peon::Peon(void) {
	std::cout << "Zog zog." << std::endl;
	return;
}

Peon::Peon(std::string const &  name) {
	this->setName(name);
	std::cout << "Zog zog." << std::endl;
	return;
}

Peon::~Peon(void) {
	std::cout << "Bleuark..." << std::endl;
	return;
}

Peon::Peon(const Peon & src) {
	*this = src;
	std::cout << "Zog zog." << std::endl;
	return;
}

Peon & Peon::operator=(const Peon & src) {
	this->setName(src.getName());
	return *this;
}

void 		Peon::getPolymorphed(void) const {
	std::cout << this->getName();
	std::cout << " has been turned into a pink pony !" << std::endl;
	return ;
}
