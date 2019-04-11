#include <Runner.hpp>
#include <iostream>

int     main(int ac, char* av[])
{
    if (ac != 2)
    {
        return -1;
    }

    Runner r;
    r.read(av[1]);
    std::cerr << "Executing" << std::endl;
    r.execute();
    return 0;
}
