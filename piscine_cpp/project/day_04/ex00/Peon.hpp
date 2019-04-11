#ifndef PEON_HPP
# define PEON_HPP

# include "Victim.hpp"
# include <iostream>

class Peon: public Victim {

public:

	Peon(void);
	Peon(const Peon &);
	~Peon(void);
	Peon & operator=(const Peon &);
	Peon(std::string const &) ;

	void 	getPolymorphed(void) const ;

private:

};

#endif
