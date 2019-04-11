#ifndef COMPONENTTEXTUI_HPP
#define COMPONENTTEXTUI_HPP

#include "Component.hpp"
#include <SFML/Graphics/Text.hpp>

class TextUI : public Component, public sf::Text{

public:

    static const Component::Type s_type;
    virtual Component* getCopy() const;

    TextUI(const std::string& content, unsigned int characterSize, const sf::Color& color);

};

#endif
