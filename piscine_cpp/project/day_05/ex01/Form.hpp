#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

// # include "Bureaucrat.hpp"
class Bureaucrat;
class Form {

public:

	Form(std::string, int, int);
	Form(const Form &);
	~Form(void);

	void 			beSigned(const Bureaucrat&);

	void			setSigned(bool);
	bool			getSigned() const;
	std::string		getName() const;
	int				getGradeSign() const;
	int				getGradeExecute() const;

	class GradeTooHighException: public std::exception
	{
	public:
		virtual const char* what() const throw();

		GradeTooHighException(void);
		virtual ~GradeTooHighException(void) throw ();
		GradeTooHighException(const GradeTooHighException&);

	private:
		GradeTooHighException& 	operator=(const GradeTooHighException&);
	};

	class GradeTooLowException: public std::exception
	{
	public:
		virtual const char* what() const throw();

		GradeTooLowException(void);
		virtual ~GradeTooLowException(void) throw ();
		GradeTooLowException(const GradeTooLowException&);

	private:
		GradeTooLowException& 	operator=(const GradeTooLowException&);
	};

	class GradeTooLowSignException: public std::exception
	{
	public:
		virtual const char* what() const throw();

		GradeTooLowSignException(void);
		virtual ~GradeTooLowSignException(void) throw ();
		GradeTooLowSignException(const GradeTooLowSignException&);

	private:
		GradeTooLowSignException& 	operator=(const GradeTooLowSignException&);
	};

private:

	Form(void);
	Form & operator=(const Form &);

	const std::string	m_name;
	bool				m_signed;
	const int 			m_gradeSign;
	const int			m_gradeExecute;

};

std::ostream&		operator<<(std::ostream&, const Form&);


#endif
