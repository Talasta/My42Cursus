#include "Human.hpp"

Human::Human(void) : _brain(new Brain()) {
	std::cout << "Human Constructed" << std::endl;
}

Human::~Human(void) {
	std::cout << "Human Destructed" << std::endl;
}


Brain&		Human::getBrain(void) const {
	Brain&	ref = *(this->_brain);
	return ref;
}

std::string	Human::identify(void) const {
	return this->_brain->identify();
}
