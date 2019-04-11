#include "Bureaucrat.hpp"

int main(int ac, char* av[])
{

    if (ac != 3)
    {
        std::cout << "usage: ./test <name> <grade>" <<  std::endl;
        return 0;
    }

    try
    {
        Bureaucrat ceo = Bureaucrat(av[1], av[2]);
        std::cout << ceo << std::endl;
        ceo--;
        ceo++;
        ceo++;
        std::cout << ceo << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
