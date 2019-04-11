#ifndef OPERATIONS_HPP
#define OPERATIONS_HPP

#include <SFML/System/Vector2.hpp>

#include <string>

unsigned int power(unsigned int x, unsigned int n);
unsigned int toNumber(const std::string& number);

unsigned int getDistance(const sf::Vector2f& basePos, const sf::Vector2f& destinationPos);

#endif
