#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Bureaucrat;

class Form
{
public:

	Form(std::string, int, int, std::string);
	Form(const Form &);
	virtual ~Form(void);

	void 			execute(const Bureaucrat&) const;
	virtual void 	executeTrue(void) const = 0;
	void 			beSigned(const Bureaucrat&);

	void			setSigned(bool);
	bool			getSigned() const;
	std::string		getName() const;
	int				getGradeSign() const;
	int				getGradeExecute() const;
	std::string		getTarget() const;

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

	class GradeTooLowExecuteException: public std::exception
	{
	public:
		virtual const char* what() const throw();

		GradeTooLowExecuteException(void);
		virtual ~GradeTooLowExecuteException(void) throw ();
		GradeTooLowExecuteException(const GradeTooLowExecuteException&);

	private:
		GradeTooLowExecuteException& 	operator=(const GradeTooLowExecuteException&);
	};
	
protected:

	Form(void);
	Form & operator=(const Form &);

	const std::string	m_name;
	bool				m_signed;
	const int 			m_gradeSign;
	const int			m_gradeExecute;
	std::string			m_target;

private:

};

std::ostream&		operator<<(std::ostream&, const Form&);


#endif
