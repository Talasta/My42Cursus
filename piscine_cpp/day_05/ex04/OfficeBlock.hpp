#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

# include "Intern.hpp"
# include "Bureaucrat.hpp"

class OfficeBlock {

public:

	OfficeBlock(void);
	OfficeBlock(Intern&, Bureaucrat&, Bureaucrat&);
	~OfficeBlock(void);

	void 			doBureaucracy(std::string, std::string);

	void 			setIntern(Intern&);
	void 			setSigner(Bureaucrat&);
	void 			setExecutor(Bureaucrat&);

	class NoFilledBureaucratieException: public std::exception
	{
	public:
		virtual const char* what() const throw();

		NoFilledBureaucratieException(void);
		virtual ~NoFilledBureaucratieException(void) throw ();
		NoFilledBureaucratieException(const NoFilledBureaucratieException&);

	private:
		NoFilledBureaucratieException& 	operator=(const NoFilledBureaucratieException&);
	};

	class InternException: public std::exception
	{
	public:
		virtual const char* what() const throw();

		InternException(void);
		virtual ~InternException(void) throw ();
		InternException(const InternException&);

	private:
		InternException& 	operator=(const InternException&);
	};

	class SigningException: public std::exception
	{
	public:
		virtual const char* what() const throw();

		SigningException(void);
		virtual ~SigningException(void) throw ();
		SigningException(const SigningException&);

	private:
		SigningException& 	operator=(const SigningException&);
	};

	class ExecutingException: public std::exception
	{
	public:
		virtual const char* what() const throw();

		ExecutingException(void);
		virtual ~ExecutingException(void) throw ();
		ExecutingException(const ExecutingException&);

	private:
		ExecutingException& 	operator=(const ExecutingException&);
	};

private:

	Intern*			m_intern;
	Bureaucrat*		m_signingBureaucrat;
	Bureaucrat*		m_executingBureaucrat;

	OfficeBlock(const OfficeBlock &);
	OfficeBlock & operator=(const OfficeBlock &);

};

#endif
