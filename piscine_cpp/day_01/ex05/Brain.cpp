#include "Brain.hpp"

Brain::Brain(void) {
	this->setNeurones(std::rand()%10000);
	std::cout << "Brain Constructed" << std::endl;
}

Brain::~Brain(void) {
	std::cout << "Brain Destructed" << std::endl;
}

void 		Brain::live(void) {
	this->setNeurones(this->getNeurones() - std::rand()%10);
}

std::string	Brain::identify(void) const {
	std::stringstream stream;
	stream << "0x";
	stream << std::setfill ('0') << std::setw(8) << std::hex << this;
	return stream.str();
}

int			Brain::getNeurones(void) { return this->_neurones; }
void		Brain::setNeurones(int nb) { this->_neurones = nb; }
