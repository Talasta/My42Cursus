#include "ComponentTextUI.hpp"

#include "Vars.hpp"


const Component::Type TextUI::s_type = Component::CTextUI;

TextUI::TextUI(const std::string& content, unsigned int characterSize, const sf::Color& color) : Component(Component::CTextUI)
{
    setString(content);
    setCharacterSize(characterSize);
    setColor(color);
    setFont(game->font);
}

Component* TextUI::getCopy() const
{
    return new TextUI(getString(), getCharacterSize(), getColor());
}
