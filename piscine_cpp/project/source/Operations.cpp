#include "Operations.hpp"

#include <cmath>


unsigned int power(unsigned int x, unsigned int n)
{
    unsigned int result = 1;
    while(--n != (unsigned int)-1)
    {
        result *= x;
    }
    return result;
}

unsigned int toNumber(const std::string& number)
{
    unsigned int result = 0, p = 0;
    for(unsigned int i = number.size(); --i != (unsigned int)-1; ++p)
    {
        result += (number[i] - '0') * power(10, p);
    }
    return result;
}

unsigned int getDistance(const sf::Vector2f& basePos, const sf::Vector2f& destinationPos)
{
    return std::abs(basePos.x - destinationPos.x) + std::abs(basePos.y - destinationPos.y);
}
