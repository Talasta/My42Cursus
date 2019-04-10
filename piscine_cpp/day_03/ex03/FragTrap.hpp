#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap {

public:

	FragTrap(void);
	FragTrap(const FragTrap &);
	~FragTrap(void);
	FragTrap & operator=(const FragTrap &);

	FragTrap(std::string);

	void 		HyperionPunch(std::string const &);
	void 		StartBang(std::string const &);
	void 		RubberGlue(std::string const &);
	void 		Combustion(std::string const &);
	void 		Loadsplode(std::string const &);
	void 		DropHammer(std::string const &);

	void 		vaulthunter_dot_exe(std::string const &);

private:

};

#endif
