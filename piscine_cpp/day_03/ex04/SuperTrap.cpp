#include "SuperTrap.hpp"

SuperTrap::SuperTrap(void) {
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
	std::cout << "New born Superboy " << this->getName() << std::endl;
	return;
}

SuperTrap::SuperTrap(std::string str) {
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
	std::cout << "New born Superboy " << this->getName() << std::endl;
	return;
}

SuperTrap::SuperTrap(const SuperTrap & src) {
	*this = src;
	std::cout << "Duplicated Superboy " << src.getName() << " into " << this->getName()<< std::endl;
	return;
}

SuperTrap::~SuperTrap(void) {
	std::cout << "Destructed Superboy " << this->getName() << std::endl;
	return;
}

SuperTrap & SuperTrap::operator=(const SuperTrap & src) {
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

std::string	SuperTrap::baseName(void) const { return "Unknown"; }
std::string	SuperTrap::baseType(void) const { return "SUP3R-TP"; }
int			SuperTrap::baseLevel(void) const { return 1; }
