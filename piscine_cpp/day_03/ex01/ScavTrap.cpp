#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) :
	_name("No name"),
	_hitPoints(100),
	_maxHitPoints(100),
	_energyPoints(50),
	_maxEnergyPoints(50),
	_level(1),
	_meleeAttackDamage(20),
	_rangedAttackDamage(15),
	_armorDamageReduction(3) {
	std::cout << "New born Scavboy " << this->getName() << std::endl;
	return;
}

ScavTrap::ScavTrap(const ScavTrap & src) {
	*this = src;
	std::cout << "Duplicated Scavboy " << src.getName() << " into " << this->getName()<< std::endl;
	return;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "Destructed Scavboy " << this->getName() << std::endl;
	return;
}

ScavTrap & ScavTrap::operator=(const ScavTrap & src) {
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

ScavTrap::ScavTrap(std::string str) :
	_name(str),
	_hitPoints(100),
	_maxHitPoints(100),
	_energyPoints(50),
	_maxEnergyPoints(50),
	_level(1),
	_meleeAttackDamage(20),
	_rangedAttackDamage(15),
	_armorDamageReduction(3) {
	std::cout << "New born Scavboy " << this->getName() << std::endl;
	return;
}

void 	ScavTrap::rangedAttack(std::string const & target) {
	std::cout << "SC4V-TP " << this->getName();
	std::cout << " attacks " << target;
	std::cout << " at range, causing " << this->getRangedAttackDamage();
	std::cout << " points of damage !";
	std::cout << std::endl;
	return;
}

void 	ScavTrap::meleeAttack(std::string const & target) {
	std::cout << "SC4V-TP " << this->getName();
	std::cout << " attacks " << target;
	std::cout << " in melee, causing " << this->getMeleeAttackDamage();
	std::cout << " points of damage !";
	std::cout << std::endl;
	return;
}

void 	ScavTrap::takeDamage(unsigned int amount) {
	int		damages = amount - this->getArmorDamageReduction();
	damages = damages < 0 ? 0 : damages;
	this->_hitPoints -= damages;
	this->_hitPoints = this->getHitPoints() < 0 ? 0 : this->getHitPoints();

	std::cout << "SC4V-TP " << this->getName();
	std::cout << " take " << damages;
	std::cout << " damages. (" << this->getHitPoints();
	std::cout << " HP)!";
	std::cout << std::endl;
	return;
}

void 	ScavTrap::beRepaired(unsigned int amount) {
	int 	hp = this->getHitPoints() + amount;
	this->_hitPoints = hp > this->getMaxHitPoints() ? this->getMaxHitPoints() : hp;

	std::cout << "SC4V-TP " << this->getName();
	std::cout << " recovered " << amount;
	std::cout << " damages. (" << this->getHitPoints();
	std::cout << " HP)!";
	std::cout << std::endl;
	return;
}

void 		ScavTrap::challengeNewcomer(void) {
	int		idx = std::rand() % 5;
	void 	(ScavTrap::*actions[])(void) = {
		&ScavTrap::challFunnyDude,
		&ScavTrap::challSlauter,
		&ScavTrap::challKungFu,
		&ScavTrap::challQuestion,
		&ScavTrap::challDiscovery,
		&ScavTrap::challJenkins
	};
	(this->*(actions[idx]))();
	return;
}

void 		ScavTrap::challFunnyDude(void) {
	std::cout << this->getName() << " says: \"Make me laugth dumb-ass!\"" << std::endl;
}

void 		ScavTrap::challSlauter(void) {
	std::cout << this->getName() << " says: \"Kill 5 enemies in succession with no more than 7 seconds in between each kill, you would be my boss.\"" << std::endl;
}

void 		ScavTrap::challKungFu(void) {
	std::cout << this->getName() << " says: \"Show me that your kung fu is best.\"" << std::endl;
}

void 		ScavTrap::challQuestion(void) {
	std::cout << this->getName() << " says: \"Who made that man a gunner?\"" << std::endl;
}

void 		ScavTrap::challDiscovery(void) {
	std::cout << this->getName() << " says: \"Discover the three hidden Vault Symbols.\"" << std::endl;
}

void 		ScavTrap::challJenkins(void) {
	std::cout << this->getName() << " says: \"Try to be ... JEEEEENKINSSSSSS!!!\"" << std::endl;
}


std::string	ScavTrap::getName(void) const { return this->_name; }
int			ScavTrap::getHitPoints(void) const { return this->_hitPoints; }
int			ScavTrap::getMaxHitPoints(void) const { return this->_maxHitPoints; }
int			ScavTrap::getEnergyPoints(void) const { return this->_energyPoints; }
int			ScavTrap::getMaxEnergyPoints(void) const { return this->_maxEnergyPoints; }
int			ScavTrap::getLevel(void) const { return this->_level; }
int			ScavTrap::getMeleeAttackDamage(void) const { return this->_meleeAttackDamage; }
int			ScavTrap::getRangedAttackDamage(void) const { return this->_rangedAttackDamage; }
int			ScavTrap::getArmorDamageReduction(void) const { return this->_armorDamageReduction; }
