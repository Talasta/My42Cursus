#ifndef COMPONENTTEXT_HPP
#define COMPONENTTEXT_HPP

#include "Component.hpp"
#include <SFML/Graphics/Text.hpp>

class Text : public Component, public sf::Text{

public:

    static const Component::Type s_type;
    virtual Component* getCopy() const;

    Text(const std::string& content, unsigned int characterSize, const sf::Color& color);
    virtual void init(Entity* owner);

    virtual void receive(const Message& msg);

};

#endif
