#include <iostream>
#include <cstdlib>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* makeA(void)
{
    return new A;
}

Base* makeB(void)
{
    return new B;
}

Base* makeC(void)
{
    return new C;
}

Base* generate(void)
{
    Base* (*g[])(void) = {&makeA, &makeB, &makeC};

    return g[rand() % 3]();
}

void identify_from_pointer(Base* p)
{
    if (dynamic_cast<A*>(p))
    {
        std::cout << "A" << std::endl;
    }
    if (dynamic_cast<B*>(p))
    {
        std::cout << "B" << std::endl;
    }
    if (dynamic_cast<C*>(p))
    {
        std::cout << "C" << std::endl;
    }
}

void identify_from_reference(Base& p)
{
    identify_from_pointer(&p);
}

int     main()
{
    Base* b;
    for (int i = 0; i < 10; ++i)
    {
        b = generate();
        identify_from_pointer(b);
        identify_from_reference(*b);
        std::cout << std::endl;
        delete b;
    }
    return 0;
}
