#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <sstream>
# include <iomanip>

class Brain {

public:

	Brain(void);
	~Brain(void);
	std::string	identify(void) const;

	void 		live(void);

	int			getNeurones(void);
	void		setNeurones(int);

private:
	int 		_neurones;

};

#endif
