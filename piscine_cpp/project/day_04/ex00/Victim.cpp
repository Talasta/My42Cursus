#include "Victim.hpp"

Victim::Victim(void) : _name("") {
	std::cout << "Some random victim called " << this->getName();
	std::cout << " just popped !" << std::endl;
	return;
}

Victim::Victim(std::string const & name) : _name(name) {
	std::cout << "Some random victim called " << this->getName();
	std::cout << " just popped !" << std::endl;
	return;
}

Victim::~Victim(void) {
	std::cout << "Victim " << this->getName();
	std::cout << " just died for no apparent reason !" << std::endl;
	return;
}

Victim::Victim(const Victim & src) {
	*this = src;
	std::cout << "Some random victim called " << this->getName();
	std::cout << " just popped !" << std::endl;
	return;
}

Victim & Victim::operator=(const Victim & src) {
	this->setName(src.getName());
	return *this;
}

void 			Victim::getPolymorphed(void) const {
	std::cout << this->getName();
	std::cout << " has been turned into a cute little sheep !" << std::endl;
	return ;
}

std::string 	Victim::getName(void) const { return this->_name; }
void 			Victim::setName(std::string val) { this->_name = val; }

std::ostream &	operator<<(std::ostream & o , Victim const & ref) {
	o << "I'm " << ref.getName() << " and I like otters !" << std::endl;
	return o;
}
