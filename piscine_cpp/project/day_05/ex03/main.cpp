#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    srand(time(NULL));

    Bureaucrat  hermes = Bureaucrat("Hermes Conrad", 12);
    Intern  someRandomIntern;
    try
    {
        Form* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        hermes.signForm(*rrf);
        hermes.executeForm(*rrf);
        delete rrf;

        Form* douze = someRandomIntern.makeForm("presidential pardon", "lol");
        hermes.signForm(*douze);
        hermes.executeForm(*douze);
        delete douze;

        Form* formel = someRandomIntern.makeForm("shrubbery creation", "Bobby");
        hermes.signForm(*formel);
        hermes.executeForm(*formel);
        delete formel;

        Form* nf = someRandomIntern.makeForm("power form", "Bender");
        hermes.signForm(*nf);
        hermes.executeForm(*nf);
        delete nf;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}
