#include "FragTrap.hpp"

FragTrap::FragTrap(void) :
	_name("No name"),
	_hitPoints(100),
	_maxHitPoints(100),
	_energyPoints(100),
	_maxEnergyPoints(100),
	_level(1),
	_meleeAttackDamage(30),
	_rangedAttackDamage(20),
	_armorDamageReduction(5) {
	std::cout << "Constructed " << this->getName() << std::endl;
	return;
}

FragTrap::FragTrap(const FragTrap & src) {
	*this = src;
	std::cout << "Copied " << src.getName() << " into " << this->getName()<< std::endl;
	return;
}

FragTrap::~FragTrap(void) {
	std::cout << "Destructed " << this->getName() << std::endl;
	return;
}

FragTrap & FragTrap::operator=(const FragTrap & src) {
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_maxHitPoints = src.getMaxHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_maxEnergyPoints = src.getMaxEnergyPoints();
	this->_level = src.getLevel();
	this->_meleeAttackDamage = src.getMeleeAttackDamage();
	this->_rangedAttackDamage = src.getRangedAttackDamage();
	this->_armorDamageReduction = src.getArmorDamageReduction();
	return *this;
}

FragTrap::FragTrap(std::string str) :
	_name(str),
	_hitPoints(100),
	_maxHitPoints(100),
	_energyPoints(100),
	_maxEnergyPoints(100),
	_level(1),
	_meleeAttackDamage(30),
	_rangedAttackDamage(20),
	_armorDamageReduction(5) {
	std::cout << "Constructed " << this->getName() << std::endl;
	return;
}

void 	FragTrap::rangedAttack(std::string const & target) {
	std::cout << "FR4G-TP " << this->getName();
	std::cout << " attacks " << target;
	std::cout << " at range, causing " << this->getRangedAttackDamage();
	std::cout << " points of damage !";
	std::cout << std::endl;
	return;
}

void 	FragTrap::meleeAttack(std::string const & target) {
	std::cout << "FR4G-TP " << this->getName();
	std::cout << " attacks " << target;
	std::cout << " in melee, causing " << this->getMeleeAttackDamage();
	std::cout << " points of damage !";
	std::cout << std::endl;
	return;
}

void 	FragTrap::takeDamage(unsigned int amount) {
	int		damages = amount - this->getArmorDamageReduction();
	damages = damages < 0 ? 0 : damages;
	this->_hitPoints -= damages;
	this->_hitPoints = this->getHitPoints() < 0 ? 0 : this->getHitPoints();

	std::cout << "FR4G-TP " << this->getName();
	std::cout << " take " << damages;
	std::cout << " damages. (" << this->getHitPoints();
	std::cout << " HP)!";
	std::cout << std::endl;
	return;
}

void 	FragTrap::beRepaired(unsigned int amount) {
	int 	hp = this->getHitPoints() + amount;
	this->_hitPoints = hp > this->getMaxHitPoints() ? this->getMaxHitPoints() : hp;

	std::cout << "FR4G-TP " << this->getName();
	std::cout << " recovered " << amount;
	std::cout << " damages. (" << this->getHitPoints();
	std::cout << " HP)!";
	std::cout << std::endl;
	return;
}

void 		FragTrap::vaulthunter_dot_exe(std::string const & target) {
	int		idx = std::rand() % 6;
	void 	(FragTrap::*actions[])(std::string const &) = {
		&FragTrap::HyperionPunch,
		&FragTrap::StartBang,
		&FragTrap::RubberGlue,
		&FragTrap::Loadsplode,
		&FragTrap::Combustion,
		&FragTrap::DropHammer
	};
	if (this->getEnergyPoints() < 25) {
		this->_energyPoints = 0;
		std::cout << this->getName() << " says: \"Oh no, I'm out of powaaa....\"" << std::endl;
		return ;
	}
	this->_energyPoints -= 25;
	(this->*(actions[idx]))(target);
	return;
}
void 		FragTrap::HyperionPunch(std::string const & target) {
	std::cout << this->getName() << " says: \"Hyperion Punch !!!\"" << std::endl;
	this->meleeAttack(target);
	return ;
}

void 		FragTrap::StartBang(std::string const & target) {
	std::cout << this->getName() << " says: \"It starts with a Bang.\"" << std::endl;
	this->rangedAttack(target);
	return ;
}
void 		FragTrap::RubberGlue(std::string const & target) {
	std::cout << this->getName() << " says: \"I am Rubber, You are Glue...\"" << std::endl;
	this->meleeAttack(target);
	return ;
}
void 		FragTrap::Loadsplode(std::string const & target) {
	std::cout << this->getName() << " says: \"Load ‘n’ splode !!!!\"" << std::endl;
	this->rangedAttack(target);
	return ;
}
void 		FragTrap::Combustion(std::string const & target) {
	std::cout << this->getName() << " says: \"Coincidental Combustion !\"" << std::endl;
	this->rangedAttack(target);
	return ;
}
void 		FragTrap::DropHammer(std::string const & target) {
	std::cout << this->getName() << " says: \"Let's drop the Hammer !\"" << std::endl;
	this->meleeAttack(target);
	return ;
}


std::string	FragTrap::getName(void) const { return this->_name; }
int			FragTrap::getHitPoints(void) const { return this->_hitPoints; }
int			FragTrap::getMaxHitPoints(void) const { return this->_maxHitPoints; }
int			FragTrap::getEnergyPoints(void) const { return this->_energyPoints; }
int			FragTrap::getMaxEnergyPoints(void) const { return this->_maxEnergyPoints; }
int			FragTrap::getLevel(void) const { return this->_level; }
int			FragTrap::getMeleeAttackDamage(void) const { return this->_meleeAttackDamage; }
int			FragTrap::getRangedAttackDamage(void) const { return this->_rangedAttackDamage; }
int			FragTrap::getArmorDamageReduction(void) const { return this->_armorDamageReduction; }
