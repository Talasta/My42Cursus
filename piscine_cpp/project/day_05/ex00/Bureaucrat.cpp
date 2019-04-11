#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : m_name(name)
{
	if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	else if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else
	{
		m_grade = grade;
	}
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
{
	*this = src;
}

Bureaucrat& 	Bureaucrat::operator=(const Bureaucrat& src)
{
	m_grade = src.getGrade();
	m_name = src.getName();
	return *this;
}

std::string		Bureaucrat::getName() const
{
	return m_name;
}

int				Bureaucrat::getGrade() const
{
	return m_grade;
}

Bureaucrat		Bureaucrat::operator++()
{
	if (m_grade == 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	m_grade -= 1;
	return *this;
}

Bureaucrat		Bureaucrat::operator++(int)
{
	Bureaucrat	b = Bureaucrat(*this);
	if (m_grade == 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	m_grade -= 1;
	return b;
}

Bureaucrat		Bureaucrat::operator--()
{
	if (m_grade == 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	m_grade += 1;
	return *this;
}

Bureaucrat		Bureaucrat::operator--(int)
{
	Bureaucrat	b = Bureaucrat(*this);
	if (m_grade == 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	m_grade += 1;
	return b;
}

std::ostream &			operator<<(std::ostream& o , const Bureaucrat&  b) {
	o << b.getName() << ", bureaucrat grade " << b.getGrade();
	return o;
}

/* GradeTooLowException Class
*/

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw ()
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void)
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const Bureaucrat::GradeTooLowException&)
{
}

/* GradeTooHighException Class
*/

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw ()
{
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void)
{
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const Bureaucrat::GradeTooHighException&)
{
}
