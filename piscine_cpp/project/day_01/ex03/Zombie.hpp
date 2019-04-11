#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {

public:

	Zombie(void);
	~Zombie(void);

	void announce(void);

	void 		setName(std::string);
	std::string	getName(void);

private:
	std::string _name;

};

#endif
