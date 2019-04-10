#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
	this->setType("FR4G-TP");
	this->setName("No name");
	this->setHitPoints(100);
	this->setMaxHitPoints(100);
	this->setEnergyPoints(100);
	this->setMaxEnergyPoints(100);
	this->setLevel(1);
	this->setMeleeAttackDamage(30);
	this->setRangedAttackDamage(20);
	this->setArmorDamageReduction(5);
	std::cout << "New born Fragboy " << this->getName() << std::endl;
	return;
}

FragTrap::FragTrap(std::string str) {
	this->setType("FR4G-TP");
	this->setName(str);
	this->setHitPoints(100);
	this->setMaxHitPoints(100);
	this->setEnergyPoints(100);
	this->setMaxEnergyPoints(100);
	this->setLevel(1);
	this->setMeleeAttackDamage(30);
	this->setRangedAttackDamage(20);
	this->setArmorDamageReduction(5);
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
