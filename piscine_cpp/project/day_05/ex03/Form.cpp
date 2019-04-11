#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) :
	m_gradeSign(1),
	m_gradeExecute(1)
{
}

Form::Form(std::string name, int gradeSign, int gradeExecute, std::string target) :
	m_name(name),
	m_signed(false),
	m_gradeSign(gradeSign),
	m_gradeExecute(gradeExecute),
	m_target(target)
{
	if (m_gradeSign > 150 || m_gradeExecute > 150)
	{
		throw Form::GradeTooLowException();
	}
	else if (m_gradeSign < 1 || m_gradeExecute < 1)
	{
		throw Form::GradeTooHighException();
	}
}

Form::~Form(void)
{
}

Form::Form(const Form& src) :
	m_name(src.getName()),
	m_signed(src.getSigned()),
	m_gradeSign(src.getGradeSign()),
	m_gradeExecute(src.getGradeExecute()),
	m_target(src.getTarget())
{
}

Form& 	Form::operator=(const Form& src)
{
	m_signed = src.getSigned();
	return *this;
}

void 			Form::execute(const Bureaucrat& src) const
{
	if (src.getGrade() > m_gradeExecute)
	{
		throw Form::GradeTooLowExecuteException();
	}
	executeTrue();
}

void 			Form::beSigned(const Bureaucrat& src)
{
	if (src.getGrade() > m_gradeSign)
	{
		throw Form::GradeTooLowSignException();
	}
	m_signed = true;
}

void			Form::setSigned(bool sign)
{
	m_signed = sign;
}

std::string		Form::getName() const
{
	return m_name;
}

std::string		Form::getTarget() const
{
	return m_target;
}

int				Form::getGradeExecute() const
{
	return m_gradeExecute;
}

int				Form::getGradeSign() const
{
	return m_gradeSign;
}

bool			Form::getSigned() const
{
	return m_signed;
}

std::ostream&			operator<<(std::ostream& o , const Form&  b) {
	o << b.getName() << ", grade to sign " << b.getGradeSign();
	o << ", grade to execute " << b.getGradeExecute();
	o << " is " << (b.getSigned() ? "" : "not ") << "signed.";
	return o;
}

/* GradeTooLowException Class
*/

const char* Form::GradeTooLowException::what() const throw()
{
	return ("grade too low to construct form");
}

Form::GradeTooLowException::~GradeTooLowException(void) throw ()
{
}

Form::GradeTooLowException::GradeTooLowException(void)
{
}

Form::GradeTooLowException::GradeTooLowException(const Form::GradeTooLowException&)
{
}

/* GradeTooHighException Class
*/

const char* Form::GradeTooHighException::what() const throw()
{
	return ("grade too high to construct form");
}

Form::GradeTooHighException::~GradeTooHighException(void) throw ()
{
}

Form::GradeTooHighException::GradeTooHighException(void)
{
}

Form::GradeTooHighException::GradeTooHighException(const Form::GradeTooHighException&)
{
}

/* GradeTooLowSignException Class
*/

const char* Form::GradeTooLowSignException::what() const throw()
{
	return ("grade too low to sign");
}

Form::GradeTooLowSignException::~GradeTooLowSignException(void) throw ()
{
}

Form::GradeTooLowSignException::GradeTooLowSignException(void)
{
}

Form::GradeTooLowSignException::GradeTooLowSignException(const Form::GradeTooLowSignException&)
{
}


/* GradeTooLowExecuteException Class
*/

const char* Form::GradeTooLowExecuteException::what() const throw()
{
	return ("grade too high to execute");
}

Form::GradeTooLowExecuteException::~GradeTooLowExecuteException(void) throw ()
{
}

Form::GradeTooLowExecuteException::GradeTooLowExecuteException(void)
{
}

Form::GradeTooLowExecuteException::GradeTooLowExecuteException(const Form::GradeTooLowExecuteException&)
{
}
