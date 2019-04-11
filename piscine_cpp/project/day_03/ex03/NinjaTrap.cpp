#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void) {
	this->setType("NINJ4-TP");
	this->setName("No name");
	this->setHitPoints(60);
	this->setMaxHitPoints(60);
	this->setEnergyPoints(120);
	this->setMaxEnergyPoints(120);
	this->setLevel(1);
	this->setMeleeAttackDamage(60);
	this->setRangedAttackDamage(5);
	this->setArmorDamageReduction(0);
	std::cout << "New born Ninjaboy " << this->getName() << std::endl;
	return;
}

NinjaTrap::NinjaTrap(std::string str) {
	this->setType("NINJ4-TP");
	this->setName(str);
	this->setHitPoints(60);
	this->setMaxHitPoints(60);
	this->setEnergyPoints(120);
	this->setMaxEnergyPoints(120);
	this->setLevel(1);
	this->setMeleeAttackDamage(60);
	this->setRangedAttackDamage(5);
	this->setArmorDamageReduction(0);
	std::cout << "New born Ninjaboy " << this->getName() << std::endl;
	return;
}

NinjaTrap::NinjaTrap(const NinjaTrap & src) {
	*this = src;
	std::cout << "Duplicated Ninjaboy " << src.getName() << " into " << this->getName()<< std::endl;
	return;
}

NinjaTrap::~NinjaTrap(void) {
	std::cout << "Destructed Ninjaboy " << this->getName() << std::endl;
	return;
}

NinjaTrap & NinjaTrap::operator=(const NinjaTrap & src) {
	this->setType(src.getType());
	this->setName(src.getName());
	this->setHitPoints(src.getHitPoints());
	this->setMaxHitPoints(src.getMaxHitPoints());
	this->setEnergyPoints(src.getEnergyPoints());
	this->setMaxEnergyPoints(src.getMaxEnergyPoints());
	this->setLevel(src.getLevel());
	this->setMeleeAttackDamage(src.getMeleeAttackDamage());
	this->setRangedAttackDamage(src.getRangedAttackDamage());
	this->setArmorDamageReduction(src.getArmorDamageReduction());
	return *this;
}

void 		NinjaTrap::ninjaShoebox(const NinjaTrap & target) {
	std::cout << this->getName();
	std::cout << " fights with style with " << target.getName() << "." << std::endl;
}

void 		NinjaTrap::ninjaShoebox(const FragTrap & target) {
	std::cout << this->getName();
	std::cout << " try to run super fast at " << target.getName() << "." << std::endl;
}

void 		NinjaTrap::ninjaShoebox(const ScavTrap & target) {
	std::cout << this->getName();
	std::cout << " listen to the sentence of " << target.getName() << "." << std::endl;
}

void 		NinjaTrap::ninjaShoebox(const ClapTrap & target) {
	std::cout << this->getName();
	std::cout << " just try to avoid killing " << target.getName() << "." << std::endl;
}
