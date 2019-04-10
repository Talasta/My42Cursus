#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>

class Victim {

public:

	Victim(void);
	Victim(const Victim &);
	~Victim(void);
	Victim & operator=(const Victim &);
	Victim(std::string const &);

	std::string 	getName(void) const ;

	void 			setName(std::string) ;

	virtual void 	getPolymorphed(void) const ;

private:
	std::string 	_name;

private:

};

std::ostream &		operator<<(std::ostream &, Victim const &);

#endif
