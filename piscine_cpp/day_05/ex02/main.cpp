#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int     main()
{
    srand(time(NULL));
    try
    {
        ShrubberyCreationForm sc("home");
        RobotomyRequestForm rr("home");
        PresidentialPardonForm pp("home");

        Bureaucrat  hermes = Bureaucrat("Hermes Conrad", 37);
        Bureaucrat  bob = Bureaucrat("Bobby Bobson", 123);
        Bureaucrat  you = Bureaucrat("Bobby Bobson", 1);

        std::cout << hermes << std::endl;
        std::cout << bob << std::endl;

        hermes.executeForm(sc);
        hermes.executeForm(rr);
        hermes.executeForm(pp);

        bob.executeForm(sc);
        bob.executeForm(rr);
        bob.executeForm(pp);

        you.signForm(sc);
        you.signForm(rr);
        you.signForm(pp);

        you.executeForm(sc);
        you.executeForm(rr);
        you.executeForm(pp);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
