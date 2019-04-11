#ifndef SORCERER_HPP
# define SORCERER_HPP

# include "Victim.hpp"
# include <iostream>

class Sorcerer {

public:

	Sorcerer(const Sorcerer &);
	~Sorcerer(void);
	Sorcerer & operator=(const Sorcerer &);
	Sorcerer(std::string const & ,std::string const &);

	std::string 	getName(void) const ;
	std::string 	getTitle(void) const ;

	void 			setName(std::string) ;
	void 			setTitle(std::string) ;

	void 			polymorph(Victim const &) const ;

private:
	Sorcerer(void);
	std::string 	_name;
	std::string 	_title;

};

std::ostream &		operator<<(std::ostream &, Sorcerer const &);

#endif
