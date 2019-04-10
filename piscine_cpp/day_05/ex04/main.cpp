#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "OfficeBlock.hpp"

int main(int ac, char* av[])
{
    if (ac != 4)
    {
        std::cout << "usage: ./test <lvl_excuter> <lvl_signer> <form_name>" <<  std::endl;
        std::cout << "\tAvailable forms: [\"shrubbery creation\", \"presidential pardon\", \"robotomy request\"]" << std::endl;
        return 0;
    }


    try
    {
        Intern idiotOne;
        Bureaucrat hermes = Bureaucrat("Hermes Conrad", std::atoi(av[1]));
        Bureaucrat bob = Bureaucrat("Bobby Bobson", std::atoi(av[2]));
        OfficeBlock ob;

        ob.setIntern(idiotOne);
        ob.setSigner(bob);
        ob.setExecutor(hermes);
        
        ob.doBureaucracy(av[3], "Pigley");
    }
    catch (OfficeBlock::NoFilledBureaucratieException & e)
    {
        std::cout << "Registered Error: " << e.what() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Unregistered Error: " << e.what() << std::endl;
    }
    return 0;
}
