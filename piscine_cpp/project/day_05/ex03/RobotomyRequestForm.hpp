#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public Form
{

public:

	RobotomyRequestForm(std::string);
	RobotomyRequestForm(const RobotomyRequestForm&);
	virtual ~RobotomyRequestForm(void);

	virtual void 	executeTrue(void) const;

private:

	RobotomyRequestForm(void);
	RobotomyRequestForm & operator=(const RobotomyRequestForm&);

};

#endif
