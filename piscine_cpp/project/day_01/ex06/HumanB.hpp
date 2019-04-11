#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB {

public:

	HumanB( std::string );
	~HumanB(void);

	void 			attack(void);

	std::string		getName(void);
	Weapon*			getWeapon(void);

	void 			setWeapon( Weapon& );

private:
	std::string 	_name;
	Weapon* 	 	_weapon;

};

#endif
