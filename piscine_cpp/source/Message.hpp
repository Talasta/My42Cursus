#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <string>
#include <SFML/System/Vector2.hpp>

class Message{

public:

    enum : unsigned char { MEventCallback = 0, MHit, MSetMove, MUse, MMove };

    Message(unsigned char messageType = 255);

    unsigned char type;

    unsigned int number;
    std::string string;
    sf::Vector2f vector;

};

#endif
