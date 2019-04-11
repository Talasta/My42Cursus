#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include "ClapTrap.hpp"

class NinjaTrap: public ClapTrap {

public:

	NinjaTrap(void);
	NinjaTrap(const NinjaTrap &);
	~NinjaTrap(void);
	NinjaTrap & operator=(const NinjaTrap &);

	NinjaTrap(std::string);

	void 		ninjaShoebox(const ClapTrap &);
	void 		ninjaShoebox(const ScavTrap &);
	void 		ninjaShoebox(const FragTrap &);
	void 		ninjaShoebox(const NinjaTrap &);

private:

};

#endif
