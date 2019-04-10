#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
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
	std::cout << "New born Fragboy " << this->getName() << std::endl;
	return;
}

FragTrap::FragTrap(std::string str) {
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
	std::cout << "New born Fragboy " << this->getName() << std::endl;
	return;
}

FragTrap::FragTrap(const FragTrap & src) {
	*this = src;
	std::cout << "Duplicated Fragboy " << src.getName() << " into " << this->getName()<< std::endl;
	return;
}

FragTrap::~FragTrap(void) {
	std::cout << "Destructed Fragboy " << this->getName() << std::endl;
	return;
}

FragTrap & FragTrap::operator=(const FragTrap & src) {
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

void 	FragTrap::rangedAttack(std::string const & target) {
	std::cout << this->getType() << " " << this->getName();
	std::cout << " attacks with strenght " << target;
	std::cout << " at range, causing " << this->getRangedAttackDamage();
	std::cout << " points of damage !";
	std::cout << std::endl;
	return;
}

void 	FragTrap::meleeAttack(std::string const & target) {
	std::cout << this->getType() << " " << this->getName();
	std::cout << " attacks weakly " << target;
	std::cout << " in melee, causing " << this->getMeleeAttackDamage();
	std::cout << " points of damage !";
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
		this->setEnergyPoints(0);
		std::cout << this->getName() << " says: \"Oh no, I'm out of powaaa....\"" << std::endl;
		return ;
	}
	this->setEnergyPoints(this->getEnergyPoints() -25);
	(this->*(actions[idx]))(target);
	return;
}

void 		FragTrap::HyperionPunch(std::string const & target) {
	std::cout << this->getName() << " says: \"Hyperion Punch !!!\" on " << target << std::endl;
	return ;
}

void 		FragTrap::StartBang(std::string const & target) {
	std::cout << this->getName() << " says: \"It starts with a Bang.\" on " << target << std::endl;
	return ;
}
void 		FragTrap::RubberGlue(std::string const & target) {
	std::cout << this->getName() << " says: \"I am Rubber, You are Glue...\" on " << target << std::endl;
	return ;
}
void 		FragTrap::Loadsplode(std::string const & target) {
	std::cout << this->getName() << " says: \"Load ‘n’ splode !!!!\" on " << target << std::endl;
	return ;
}
void 		FragTrap::Combustion(std::string const & target) {
	std::cout << this->getName() << " says: \"Coincidental Combustion !\" on " << target << std::endl;
	return ;
}
void 		FragTrap::DropHammer(std::string const & target) {
	std::cout << this->getName() << " says: \"Let's drop the Hammer !\" on " << target << std::endl;
	return ;
}

std::string	FragTrap::baseType(void) const { return "FR4G-TP"; }
std::string	FragTrap::baseName(void) const { return "No name"; }
int			FragTrap::baseHitPoints(void) const { return 100; }
int			FragTrap::baseMaxHitPoints(void) const { return 100; }
int			FragTrap::baseEnergyPoints(void) const { return 100; }
int			FragTrap::baseMaxEnergyPoints(void) const { return 100; }
int			FragTrap::baseLevel(void) const { return 1; }
int			FragTrap::baseMeleeAttackDamage(void) const { return 30; }
int			FragTrap::baseRangedAttackDamage(void) const { return 20; }
int			FragTrap::baseArmorDamageReduction(void) const { return 5; }
