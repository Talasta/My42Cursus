#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <iostream>

class Human {

public:
	Human(void);
	~Human(void);

	void action(std::string const & action_name, std::string const & target);

private:
	void meleeAttack(std::string const & target);
	void rangedAttack(std::string const & target);
	void intimidatingShout(std::string const & target);

};
#endif
