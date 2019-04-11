#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "Brain.hpp"
# include <iostream>

class Human {

public:

	Human( void );
	~Human( void );
	std::string	 identify( void ) const;
	Brain& 		 getBrain(void) const;

private:
	Brain* const _brain;

};

#endif
