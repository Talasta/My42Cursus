#include "Human.hpp"

Human::Human(void) {
	std::cout << "Constructed" << std::endl;
}

Human::~Human(void) {
	std::cout << "Destructed" << std::endl;
}

void Human::action(std::string const & action_name, std::string const & target) {
	std::string 					   list[] = {"melee", "ranged", "intimidating"};
	void(Human::*func[])(std::string const &) = {&Human::intimidatingShout, &Human::rangedAttack, &Human::meleeAttack};

	for (int i = 0; i < 3; i++) {
		if (list[i].compare(action_name) == 0) {
			(this->*(func[i]))(target);
			return ;
		}
	}
}

void Human::meleeAttack(std::string const & target) {
	std::cout << "Fight closely " + target + " (like a big dude)."<< std::endl;
}

void Human::rangedAttack(std::string const & target) {
	std::cout << "Fight for fram away (like a coward) " + target + "."<< std::endl;
}

void Human::intimidatingShout(std::string const & target) {
	std::cout << "Shout at " + target + " that he is a little girl."<< std::endl;
}
