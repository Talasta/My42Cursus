#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {

public:

	ClapTrap(void);
	ClapTrap(const ClapTrap &);
	~ClapTrap(void);
	ClapTrap & operator=(const ClapTrap &);

	ClapTrap(std::string);

	void 		rangedAttack(std::string const &);
	void 		meleeAttack(std::string const &);
	void 		takeDamage(unsigned int);
	void 		beRepaired(unsigned int);

	std::string	getType(void) const ;
	std::string	getName(void) const ;
	int			getHitPoints(void) const ;
	int			getMaxHitPoints(void) const ;
	int			getEnergyPoints(void) const ;
	int			getMaxEnergyPoints(void) const ;
	int			getLevel(void) const ;
	int			getMeleeAttackDamage(void) const ;
	int			getRangedAttackDamage(void) const ;
	int			getArmorDamageReduction(void) const ;

protected:
	void 		setType(std::string);
	void 		setName(std::string);
	void 		setHitPoints(int);
	void 		setMaxHitPoints(int);
	void 		setEnergyPoints(int);
	void 		setMaxEnergyPoints(int);
	void 		setLevel(int);
	void 		setMeleeAttackDamage(int);
	void 		setRangedAttackDamage(int);
	void 		setArmorDamageReduction(int);

	std::string	baseType(void) const ;
	std::string	baseName(void) const ;
	int			baseHitPoints(void) const ;
	int			baseMaxHitPoints(void) const ;
	int			baseEnergyPoints(void) const ;
	int			baseMaxEnergyPoints(void) const ;
	int			baseLevel(void) const ;
	int			baseMeleeAttackDamage(void) const ;
	int			baseRangedAttackDamage(void) const ;
	int			baseArmorDamageReduction(void) const ;

private:
	std::string		_type;
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
