#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {
	this->setType("SC4V-TP");
	this->setName("No name");
	this->setHitPoints(100);
	this->setMaxHitPoints(100);
	this->setEnergyPoints(50);
	this->setMaxEnergyPoints(50);
	this->setLevel(1);
	this->setMeleeAttackDamage(20);
	this->setRangedAttackDamage(15);
	this->setArmorDamageReduction(3);
	std::cout << "New born Scavboy " << this->getName() << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string str) {
	this->setType("SC4V-TP");
	this->setName(str);
	this->setHitPoints(100);
	this->setMaxHitPoints(100);
	this->setEnergyPoints(50);
	this->setMaxEnergyPoints(50);
	this->setLevel(1);
	this->setMeleeAttackDamage(20);
	this->setRangedAttackDamage(15);
	this->setArmorDamageReduction(3);
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
