#include <cstring>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

void printChar(char c) {
    if (std::isprint(c)) {
        std::cout << '\'' << c << '\'';
    } else {
        std::cout << "Non displayable";
    }
}

int     main(int ac, char* av[])
{
    if (ac != 2)
    {
        return -1;
    }
    double nb;

    std::string str (av[1]);
    if (!std::isdigit(str[0]) && str[0] != '-' && str[0] != '+' && str.length() != 1)
    {
        std::cout << "An error occured." << std::endl;
        return 0;
    }
    if (str[str.length() - 1] == 'f' && str.length() != 1)
        str[str.length() - 1] = '\0';
    if (std::isdigit(str[0]) || str[0] == '-' || str[0] == '+')
    {
        std::istringstream iss (str);
        iss >> nb;
    }
    else
    {
        nb = static_cast<double>(str[0]);
    }

    std::cout << "char: ";
    if (nb != nb || nb == +std::numeric_limits<double>::infinity()
            || nb == -std::numeric_limits<double>::infinity()
            || nb == +std::numeric_limits<float>::infinity()
            || nb == -std::numeric_limits<float>::infinity())
    {
        std::cout << "impossible" << std::endl;
    }
    else
    {
        printChar(static_cast<char>(nb));
    }

    std::cout << std::endl << "int: ";
    if (nb != nb || nb == +std::numeric_limits<double>::infinity()
            || nb == -std::numeric_limits<double>::infinity()
            || nb == +std::numeric_limits<float>::infinity()
            || nb == -std::numeric_limits<float>::infinity())
    {
        std::cout << "impossible" << std::endl;
    }
    else
    {
        std::cout << static_cast<int>(nb) << std::endl;
    }

    std::stringstream ss;
    ss << static_cast<float>(nb);
    std::string out = ss.str();

    std::string add ("");
    int i;
    for (i = 0; static_cast<unsigned int>(i) < out.length(); ++i)
    {
        if (out[i] == '.')
            break;
    }
    if (static_cast<unsigned int>(i) == out.length())
        add = ".0";
    std::cout << "float: ";
    std::cout << static_cast<float>(nb) << add << "f" << std::endl;

    std::cout << "double: ";
    std::cout << static_cast<double>(nb) << add << std::endl;

    return 0;
}
