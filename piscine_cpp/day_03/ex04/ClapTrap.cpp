#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
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
	std::cout << "New born ClapTrap " << this->getName() << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string str) {
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
	std::cout << "New born ClapTrap " << this->getName() << std::endl;
	return;
}

ClapTrap::ClapTrap(const ClapTrap & src) {
	*this = src;
	std::cout << "Duplicated ClapTrap " << src.getName() << " into " << this->getName()<< std::endl;
	return;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Destructed ClapTrap " << this->getName() << std::endl;
	return;
}

ClapTrap & ClapTrap::operator=(const ClapTrap & src) {
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

void 	ClapTrap::rangedAttack(std::string const & target) {
	std::cout << this->getType() << " " << this->getName();
	std::cout << " attacks " << target;
	std::cout << " at range, causing " << this->getRangedAttackDamage();
	std::cout << " points of damage !";
	std::cout << std::endl;
	return;
}

void 	ClapTrap::meleeAttack(std::string const & target) {
	std::cout << this->getType() << " " << this->getName();
	std::cout << " attacks " << target;
	std::cout << " in melee, causing " << this->getMeleeAttackDamage();
	std::cout << " points of damage !";
	std::cout << std::endl;
	return;
}

void 	ClapTrap::takeDamage(unsigned int amount) {
	int		damages = amount - this->getArmorDamageReduction();
	damages = damages < 0 ? 0 : damages;
	this->setHitPoints(this->getHitPoints() - damages);
	this->setHitPoints(this->getHitPoints() < 0 ? 0 : this->getHitPoints());

	std::cout << this->getName();
	std::cout << " take " << damages;
	std::cout << " damages. (" << this->getHitPoints();
	std::cout << " HP)!";
	std::cout << std::endl;
	return;
}

void 	ClapTrap::beRepaired(unsigned int amount) {
	int 	hp = this->getHitPoints() + amount;
	this->setHitPoints(hp > this->getMaxHitPoints() ? this->getMaxHitPoints() : hp);

	std::cout << this->getName();
	std::cout << " recovered " << amount;
	std::cout << " damages. (" << this->getHitPoints();
	std::cout << " HP)!";
	std::cout << std::endl;
	return;
}

std::string	ClapTrap::baseType(void) const { return "CL4P-TP"; }
std::string	ClapTrap::baseName(void) const { return "No name"; }
int			ClapTrap::baseHitPoints(void) const { return 0; }
int			ClapTrap::baseMaxHitPoints(void) const { return 0; }
int			ClapTrap::baseEnergyPoints(void) const { return 0; }
int			ClapTrap::baseMaxEnergyPoints(void) const { return 0; }
int			ClapTrap::baseLevel(void) const { return 0; }
int			ClapTrap::baseMeleeAttackDamage(void) const { return 0; }
int			ClapTrap::baseRangedAttackDamage(void) const { return 0; }
int			ClapTrap::baseArmorDamageReduction(void) const { return 0; }

std::string	ClapTrap::getType(void) const { return this->_type; }
std::string	ClapTrap::getName(void) const { return this->_name; }
int			ClapTrap::getHitPoints(void) const { return this->_hitPoints; }
int			ClapTrap::getMaxHitPoints(void) const { return this->_maxHitPoints; }
int			ClapTrap::getEnergyPoints(void) const { return this->_energyPoints; }
int			ClapTrap::getMaxEnergyPoints(void) const { return this->_maxEnergyPoints; }
int			ClapTrap::getLevel(void) const { return this->_level; }
int			ClapTrap::getMeleeAttackDamage(void) const { return this->_meleeAttackDamage; }
int			ClapTrap::getRangedAttackDamage(void) const { return this->_rangedAttackDamage; }
int			ClapTrap::getArmorDamageReduction(void) const { return this->_armorDamageReduction; }

void 		ClapTrap::setType(std::string val) { this->_type = val; }
void 		ClapTrap::setName(std::string val) { this->_name = val; }
void 		ClapTrap::setHitPoints(int val) { this->_hitPoints = val; }
void 		ClapTrap::setMaxHitPoints(int val) { this->_maxHitPoints = val; }
void 		ClapTrap::setEnergyPoints(int val) { this->_energyPoints = val; }
void 		ClapTrap::setMaxEnergyPoints(int val) { this->_maxEnergyPoints = val; }
void 		ClapTrap::setLevel(int val) { this->_level = val; }
void 		ClapTrap::setMeleeAttackDamage(int val) { this->_meleeAttackDamage = val; }
void 		ClapTrap::setRangedAttackDamage(int val) { this->_rangedAttackDamage = val; }
void 		ClapTrap::setArmorDamageReduction(int val) { this->_armorDamageReduction = val; }
