#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {

public:

	ScavTrap(void);
	ScavTrap(const ScavTrap &);
	~ScavTrap(void);
	ScavTrap & operator=(const ScavTrap &);

	ScavTrap(std::string);

	void 		challengeNewcomer(void) ;

	void 		challFunnyDude(void) ;
	void 		challSlauter(void) ;
	void 		challKungFu(void) ;
	void 		challQuestion(void) ;
	void 		challDiscovery(void) ;
	void 		challJenkins(void) ;

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
