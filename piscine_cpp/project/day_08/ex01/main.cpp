#include "span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(-30);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    try
    {
        sp.addNumber(11);
    }
    catch (std::exception& e)
    {
        std::cout << "Error catched : " << e.what() << std::endl;
    }
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span s_empty = Span(5);
    s_empty.addNumber(5);
    try
    {
        std::cout << s_empty.shortestSpan() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Error catched : " << e.what() << std::endl;
    }

}
