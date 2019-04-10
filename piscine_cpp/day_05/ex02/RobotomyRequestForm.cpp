#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
    Form("RobotomyRequest", 72 , 45, target)
{
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

// Makes some drilling noises, and tells us that <target> has been robotomized
// successfully 50% of the time. the rest of times, tells us it’s a failure.
void 	RobotomyRequestForm::executeTrue(void) const
{
    std::cout << "Bzzzzzzz..." << std::endl;
    if (rand() % 2 == 1)
    {
        std::cout << m_target << " has been robotomized." << std::endl;
    }
    else
    {
        std::cout << m_target << " hasn't been robotomized." << std::endl;
    }
}
