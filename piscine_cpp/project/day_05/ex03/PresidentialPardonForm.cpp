#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form()
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	Form("PresidentialPardon", 25, 5, target)
{
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

// Tells us <target> has been pardoned by Zaphod Beeblebrox.
void 	PresidentialPardonForm::executeTrue(void) const
{
	std::cout << m_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
