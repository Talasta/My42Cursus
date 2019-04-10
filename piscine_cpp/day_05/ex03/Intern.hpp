#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {

public:

	Intern(void);
	Intern(const Intern &);
	~Intern(void);

	Form*	makeForm(std::string, std::string);

	class NotRegisteredFormException: public std::exception
	{
	public:
		virtual const char* what() const throw();

		NotRegisteredFormException(void);
		virtual ~NotRegisteredFormException(void) throw ();
		NotRegisteredFormException(const NotRegisteredFormException&);

	private:
		NotRegisteredFormException& 	operator=(const NotRegisteredFormException&);
	};

private:

	Form*	makeRobotomy(std::string);
	Form*	makePresidential(std::string);
	Form*	makeShrubbery(std::string);

	Intern& operator=(const Intern &);

};

#endif
