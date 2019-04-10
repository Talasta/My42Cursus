#include "Sorcerer.hpp"

Sorcerer::Sorcerer(void) : _name(""), _title("") {
	std::cout << this->getName() << ", " << this->getTitle();
	std::cout << ", is born !" << std::endl;
	return;
}

Sorcerer::Sorcerer(std::string const & name,std::string const & title) : _name(name), _title(title) {
	std::cout << this->getName() << ", " << this->getTitle();
	std::cout << ", is born !" << std::endl;
	return;
}

Sorcerer::~Sorcerer(void) {
	std::cout << this->getName() << ", " << this->getTitle();
	std::cout << ", is dead. Consequences will never be the same !" << std::endl;
	return;
}

Sorcerer::Sorcerer(const Sorcerer & src) {
	*this = src;
	std::cout << this->getName() << ", " << this->getTitle();
	std::cout << ", is born !" << std::endl;
	return;
}

Sorcerer & Sorcerer::operator=(const Sorcerer & src) {
	this->setName(src.getName());
	this->setTitle(src.getTitle());
	return *this;
}

void 			Sorcerer::polymorph(Victim const & ref) const {
	ref.getPolymorphed();
}

std::string 	Sorcerer::getName(void) const { return this->_name; }
std::string 	Sorcerer::getTitle(void) const { return this->_title; }
void 			Sorcerer::setName(std::string val) { this->_name = val; }
void 			Sorcerer::setTitle(std::string val) { this->_title = val; }

std::ostream &	operator<<(std::ostream & o , Sorcerer const & ref) {
	o << "I am " << ref.getName() << ", " << ref.getTitle() << ", and I like ponies !" << std::endl;
	return o;
}
