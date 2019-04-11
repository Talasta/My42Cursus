#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon {

public:

	Weapon( std::string );
	~Weapon(void);

	void 				setType ( std::string );
	const std::string& 	getType( void );

private:
	std::string		_type;

};

#endif
