#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form
{

public:

	PresidentialPardonForm(std::string);
	PresidentialPardonForm(const PresidentialPardonForm &);
	virtual ~PresidentialPardonForm(void);

	virtual void 	executeTrue(void) const;

private:

	PresidentialPardonForm(void);
	PresidentialPardonForm & operator=(const PresidentialPardonForm &);

};

#endif
