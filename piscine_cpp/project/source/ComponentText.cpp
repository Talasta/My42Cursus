#include "ComponentText.hpp"

#include "Vars.hpp"


const Component::Type Text::s_type = Component::CText;

Text::Text(const std::string& content, unsigned int characterSize, const sf::Color& color) : Component(Component::CText)
{
    setString(content);
    setCharacterSize(characterSize);
    setColor(color);
    setFont(game->font);
}

void Text::init(Entity* owner)
{
    setPosition(owner->getPosition() - sf::Vector2f(getGlobalBounds().width / 2, getGlobalBounds().height));
}

Component* Text::getCopy() const
{
    return new Text(getString(), getCharacterSize(), getColor());
}

void Text::receive(const Message& msg)
{
    if(msg.type == Message::MMove)
    {
        move(msg.vector);
    }
}
