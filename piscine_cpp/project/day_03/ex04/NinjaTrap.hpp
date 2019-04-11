#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include "ClapTrap.hpp"

class NinjaTrap: virtual public ClapTrap {

public:

	NinjaTrap(void);
	NinjaTrap(const NinjaTrap &);
	~NinjaTrap(void);
	NinjaTrap & operator=(const NinjaTrap &);

	void 		rangedAttack(std::string const &);
	void 		meleeAttack(std::string const &);

	NinjaTrap(std::string);

	void 		ninjaShoebox(const ClapTrap &);
	void 		ninjaShoebox(const ScavTrap &);
	void 		ninjaShoebox(const FragTrap &);
	void 		ninjaShoebox(const NinjaTrap &);

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
