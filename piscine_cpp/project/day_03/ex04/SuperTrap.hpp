#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include "ClapTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap: public NinjaTrap, public FragTrap {

public:

	SuperTrap(void);
	SuperTrap(const SuperTrap &);
	~SuperTrap(void);
	SuperTrap & operator=(const SuperTrap &);

	SuperTrap(std::string);

	using 		FragTrap::rangedAttack;
	using 		NinjaTrap::meleeAttack;

protected:
	std::string baseName(void) const ;
	std::string	baseType(void) const ;
	int			baseLevel(void) const ;

	using 		FragTrap::baseHitPoints;
	using		FragTrap::baseMaxHitPoints;
	using		NinjaTrap::baseEnergyPoints;
	using		NinjaTrap::baseMaxEnergyPoints;
	using		NinjaTrap::baseMeleeAttackDamage;
	using		FragTrap::baseRangedAttackDamage;
	using		FragTrap::baseArmorDamageReduction;

private:

};

#endif
