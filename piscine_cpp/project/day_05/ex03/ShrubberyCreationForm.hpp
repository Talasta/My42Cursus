#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"

class ShrubberyCreationForm : public Form
{

public:

	ShrubberyCreationForm(std::string);
	ShrubberyCreationForm(const ShrubberyCreationForm &);
	virtual ~ShrubberyCreationForm(void);

	virtual void 	executeTrue(void) const;

private:

	ShrubberyCreationForm(void);
	ShrubberyCreationForm & operator=(const ShrubberyCreationForm &);

};

#endif
