#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try
    {
        Form f1245("1245", 18, 155);
        std::cout << f1245 << std::endl;
        Form f8452("8452", 18, 19);
        std::cout << f8452 << std::endl;
        Bureaucrat ceo("ceo", 42);
        Bureaucrat cto("cto", 18);
        std::cout << cto << std::endl;
        ceo.signForm(f8452);
        cto.signForm(f8452);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;;
    }
}
