#include "iter.cpp"
#include <iostream>

void    add(const int& number)
{
    int*    n = const_cast<int*>(&number);
    *n += 1;
}

int     main(void)
{
    unsigned int    len = 10;
    int             list[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Before iter: " << std::endl;
    for (unsigned int i = 0; i < len; ++i)
    {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;;

    iter(list, len, add);

    std::cout << "After iter: " << std::endl;
    for (unsigned int i = 0; i < len; ++i)
    {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
