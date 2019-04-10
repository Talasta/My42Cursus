#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>

# include "Form.hpp"

class Bureaucrat
{

public:

	Bureaucrat(std::string, int);
	~Bureaucrat(void);
	Bureaucrat(const Bureaucrat&);

	void 			signForm(Form&);

	std::string		getName() const;
	int 			getGrade() const;

	Bureaucrat		operator++();
	Bureaucrat		operator++(int);
	Bureaucrat		operator--();
	Bureaucrat		operator--(int);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();

		GradeTooHighException(void);
		virtual ~GradeTooHighException(void) throw ();
		GradeTooHighException(const GradeTooHighException&);

	private:
		GradeTooHighException& 	operator=(const GradeTooHighException&);
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();

		GradeTooLowException(void);
		virtual ~GradeTooLowException(void) throw ();
		GradeTooLowException(const GradeTooLowException&);

	private:
		GradeTooLowException& 	operator=(const GradeTooLowException&);
	};

private:
	std::string		m_name;
	int 			m_grade;

	Bureaucrat(void);
	Bureaucrat& 	operator=(const Bureaucrat&);

};

std::ostream &			operator<<(std::ostream&, const Bureaucrat&);

#endif
