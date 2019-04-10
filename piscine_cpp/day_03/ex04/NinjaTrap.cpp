#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void) {
	this->setName(this->baseName());
	this->setType(this->baseType());
	this->setHitPoints(this->baseHitPoints());
	this->setMaxHitPoints(this->baseMaxHitPoints());
	this->setEnergyPoints(this->baseEnergyPoints());
	this->setMaxEnergyPoints(this->baseMaxEnergyPoints());
	this->setLevel(this->baseLevel());
	this->setMeleeAttackDamage(this->baseMeleeAttackDamage());
	this->setRangedAttackDamage(this->baseRangedAttackDamage());
	this->setArmorDamageReduction(this->baseArmorDamageReduction());
	std::cout << "New born Ninjaboy " << this->getName() << std::endl;
	return;
}

NinjaTrap::NinjaTrap(std::string str) {
	this->setName(str);
	this->setType(this->baseType());
	this->setHitPoints(this->baseHitPoints());
	this->setMaxHitPoints(this->baseMaxHitPoints());
	this->setEnergyPoints(this->baseEnergyPoints());
	this->setMaxEnergyPoints(this->baseMaxEnergyPoints());
	this->setLevel(this->baseLevel());
	this->setMeleeAttackDamage(this->baseMeleeAttackDamage());
	this->setRangedAttackDamage(this->baseRangedAttackDamage());
	this->setArmorDamageReduction(this->baseArmorDamageReduction());
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

void 	NinjaTrap::rangedAttack(std::string const & target) {
	std::cout << this->getType() << " " << this->getName();
	std::cout << " attacks weakly " << target;
	std::cout << " at range, causing " << this->getRangedAttackDamage();
	std::cout << " points of damage !";
	std::cout << std::endl;
	return;
}

void 	NinjaTrap::meleeAttack(std::string const & target) {
	std::cout << this->getType() << " " << this->getName();
	std::cout << " attacks  with strenght " << target;
	std::cout << " in melee, causing " << this->getMeleeAttackDamage();
	std::cout << " points of damage !";
	std::cout << std::endl;
	return;
}

void 		NinjaTrap::ninjaShoebox(const NinjaTrap & target) {
	std::cout << this->getName() << " fights with style with ";
	std::cout << target.getName() << "." << std::endl;
}

void 		NinjaTrap::ninjaShoebox(const FragTrap & target) {
	std::cout << this->getName() << " try to run super fast at ";
	std::cout << target.getName() << "." << std::endl;
}

void 		NinjaTrap::ninjaShoebox(const ScavTrap & target) {
	std::cout << this->getName() << " listen to the sentence of ";
	std::cout << target.getName() << "." << std::endl;
}

void 		NinjaTrap::ninjaShoebox(const ClapTrap & target) {
	std::cout << this->getName() << " just try to avoid killing ";
	std::cout << target.getName() << "." << std::endl;
}

std::string	NinjaTrap::baseType(void) const { return "NINJ4-TP"; }
std::string	NinjaTrap::baseName(void) const { return "No name"; }
int			NinjaTrap::baseHitPoints(void) const { return 60; }
int			NinjaTrap::baseMaxHitPoints(void) const { return 60; }
int			NinjaTrap::baseEnergyPoints(void) const { return 120; }
int			NinjaTrap::baseMaxEnergyPoints(void) const { return 120; }
int			NinjaTrap::baseLevel(void) const { return 1; }
int			NinjaTrap::baseMeleeAttackDamage(void) const { return 60; }
int			NinjaTrap::baseRangedAttackDamage(void) const { return 5; }
int			NinjaTrap::baseArmorDamageReduction(void) const { return 0; }
