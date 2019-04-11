#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock(void) :
	m_intern(NULL),
	m_signingBureaucrat(NULL),
	m_executingBureaucrat(NULL)
{
}

OfficeBlock::OfficeBlock(Intern& intern, Bureaucrat& signing, Bureaucrat& executing) :
	m_intern(&intern),
	m_signingBureaucrat(&signing),
	m_executingBureaucrat(&executing)
{
}

OfficeBlock::~OfficeBlock(void)
{
}

void 			OfficeBlock::doBureaucracy(std::string formname, std::string target)
{
	if (!m_intern || !m_signingBureaucrat || !m_executingBureaucrat)
	{
		throw OfficeBlock::NoFilledBureaucratieException();
	}
	
	try
	{
		Form* form = m_intern->makeForm(formname, target);
        m_signingBureaucrat->signForm(*form);
        m_executingBureaucrat->executeForm(*form);
	}
	catch (Intern::NotRegisteredFormException& e)
	{
		throw OfficeBlock::InternException();
	}
	catch (Form::GradeTooLowSignException& e)
	{
		throw OfficeBlock::SigningException();
	}
	catch (Form::GradeTooLowExecuteException& e)
	{
		throw OfficeBlock::ExecutingException();
	}
}

void 			OfficeBlock::setIntern(Intern& src)
{
	m_intern = &src;
}

void 			OfficeBlock::setSigner(Bureaucrat& src)
{
	m_signingBureaucrat = &src;
}

void 			OfficeBlock::setExecutor(Bureaucrat& src)
{
	m_executingBureaucrat = &src;
}

/* NoFilledBureaucratieException Class
*/

const char* OfficeBlock::NoFilledBureaucratieException::what() const throw()
{
	return ("Missing peoples in OfficeBlock");
}

OfficeBlock::NoFilledBureaucratieException::~NoFilledBureaucratieException(void) throw ()
{
}

OfficeBlock::NoFilledBureaucratieException::NoFilledBureaucratieException(void)
{
}

OfficeBlock::NoFilledBureaucratieException::NoFilledBureaucratieException(const OfficeBlock::NoFilledBureaucratieException&)
{
}

/* NoFilledBureaucratieException Class
*/

const char* OfficeBlock::InternException::what() const throw()
{
	return ("Intern is not good enought");
}

OfficeBlock::InternException::~InternException(void) throw ()
{
}

OfficeBlock::InternException::InternException(void)
{
}

OfficeBlock::InternException::InternException(const OfficeBlock::InternException&)
{
}

/* NoFilledBureaucratieException Class
*/

const char* OfficeBlock::SigningException::what() const throw()
{
	return ("Office is too bad to sign");
}

OfficeBlock::SigningException::~SigningException(void) throw ()
{
}

OfficeBlock::SigningException::SigningException(void)
{
}

OfficeBlock::SigningException::SigningException(const OfficeBlock::SigningException&)
{
}

/* NoFilledBureaucratieException Class
*/

const char* OfficeBlock::ExecutingException::what() const throw()
{
	return ("Office is too bad to execute");
}

OfficeBlock::ExecutingException::~ExecutingException(void) throw ()
{
}

OfficeBlock::ExecutingException::ExecutingException(void)
{
}

OfficeBlock::ExecutingException::ExecutingException(const OfficeBlock::ExecutingException&)
{
}
