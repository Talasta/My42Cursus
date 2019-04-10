#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>

class FragTrap {

public:

	FragTrap(void);
	FragTrap(const FragTrap &);
	~FragTrap(void);
	FragTrap & operator=(const FragTrap &);

	FragTrap(std::string);

	void 		rangedAttack(std::string const &);
	void 		meleeAttack(std::string const &);
	void 		takeDamage(unsigned int);
	void 		beRepaired(unsigned int);

	void 		HyperionPunch(std::string const &);
	void 		StartBang(std::string const &);
	void 		RubberGlue(std::string const &);
	void 		Combustion(std::string const &);
	void 		Loadsplode(std::string const &);
	void 		DropHammer(std::string const &);

	void 		vaulthunter_dot_exe(std::string const &);

	std::string	getName(void) const ;
	int			getHitPoints(void) const ;
	int			getMaxHitPoints(void) const ;
	int			getEnergyPoints(void) const ;
	int			getMaxEnergyPoints(void) const ;
	int			getLevel(void) const ;
	int			getMeleeAttackDamage(void) const ;
	int			getRangedAttackDamage(void) const ;
	int			getArmorDamageReduction(void) const ;

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
