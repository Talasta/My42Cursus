#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA {

public:

	HumanA( std::string, Weapon& );
	~HumanA(void);

	void 	attack(void);

	std::string	getName(void);
	Weapon&		getWeapon(void);

private:
	std::string _name;
	Weapon&		_weapon;

};

#endif
