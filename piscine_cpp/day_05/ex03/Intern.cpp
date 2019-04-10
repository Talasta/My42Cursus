#include "Intern.hpp"

Intern::Intern(void)
{
}

Intern::Intern(const Intern & src)
{
	*this = src;
}

Intern::~Intern(void)
{
}

Intern& Intern::operator=(const Intern &)
{
	return *this;
}

Form*	Intern::makeRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

Form*	Intern::makePresidential(std::string target)
{
	return new PresidentialPardonForm(target);
}

Form*	Intern::makeShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

Form*	Intern::makeForm(std::string formdata, std::string target)
{
	Form*	form;

	std::string list[] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	Form*(Intern::*func[])(std::string) = {&Intern::makeRobotomy, &Intern::makePresidential, &Intern::makeShrubbery};


	int i = 0;
	for (i = 0; i < 3; i++) {
		if (list[i].compare(formdata) == 0) {
			form = (this->*(func[i]))(target);
			std::cout << "Intern creates " << (*form) << std::endl;
			break;
		}
	}
	if (i == 3)
	{
		throw Intern::NotRegisteredFormException();
	}
	return form;
}

/* NotRegisteredFormException Class
*/

const char* Intern::NotRegisteredFormException::what() const throw()
{
	return ("Not existing form");
}

Intern::NotRegisteredFormException::~NotRegisteredFormException(void) throw ()
{
}

Intern::NotRegisteredFormException::NotRegisteredFormException(void)
{
}

Intern::NotRegisteredFormException::NotRegisteredFormException(const Intern::NotRegisteredFormException&)
{
}
