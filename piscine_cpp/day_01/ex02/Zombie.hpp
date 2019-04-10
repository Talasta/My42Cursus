#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie {

public:

	Zombie( std::string, std::string );
	~Zombie( void );

	void 		announce( void );

	std::string	getName(void);
	std::string	getType(void);

private:
	std::string _name;
	std::string _type;

};

#endif
