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

private:

};

#endif
