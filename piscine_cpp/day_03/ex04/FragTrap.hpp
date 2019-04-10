#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap {

public:

	FragTrap(void);
	FragTrap(const FragTrap &);
	~FragTrap(void);
	FragTrap & operator=(const FragTrap &);

	void 		rangedAttack(std::string const &);
	void 		meleeAttack(std::string const &);

	FragTrap(std::string);

	void 		HyperionPunch(std::string const &);
	void 		StartBang(std::string const &);
	void 		RubberGlue(std::string const &);
	void 		Combustion(std::string const &);
	void 		Loadsplode(std::string const &);
	void 		DropHammer(std::string const &);

	void 		vaulthunter_dot_exe(std::string const &);

protected:
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

};

#endif
