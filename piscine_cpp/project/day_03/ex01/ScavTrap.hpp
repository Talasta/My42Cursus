#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>

class ScavTrap {

public:

	ScavTrap(void);
	ScavTrap(const ScavTrap &);
	~ScavTrap(void);
	ScavTrap & operator=(const ScavTrap &);

	ScavTrap(std::string);

	void 		rangedAttack(std::string const &);
	void 		meleeAttack(std::string const &);
	void 		takeDamage(unsigned int);
	void 		beRepaired(unsigned int);

	std::string	getName(void) const ;
	int			getHitPoints(void) const ;
	int			getMaxHitPoints(void) const ;
	int			getEnergyPoints(void) const ;
	int			getMaxEnergyPoints(void) const ;
	int			getLevel(void) const ;
	int			getMeleeAttackDamage(void) const ;
	int			getRangedAttackDamage(void) const ;
	int			getArmorDamageReduction(void) const ;

	void 		challengeNewcomer(void) ;

	void 		challFunnyDude(void) ;
	void 		challSlauter(void) ;
	void 		challKungFu(void) ;
	void 		challQuestion(void) ;
	void 		challDiscovery(void) ;
	void 		challJenkins(void) ;


private:
	std::string		_name;
	int				_hitPoints;
	int				_maxHitPoints;
	int				_energyPoints;
	int				_maxEnergyPoints;
	int				_level;
	int				_meleeAttackDamage;
	int				_rangedAttackDamage;
	int				_armorDamageReduction;

};

#endif
