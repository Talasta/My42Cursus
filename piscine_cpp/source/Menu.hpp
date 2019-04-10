#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics/Text.hpp>

class Menu{

protected:

    Menu(unsigned char escAction);

    bool updateMenu();

    void drawMenu() const;

    void newText(const std::string& content, const sf::Vector2u& position, unsigned int characterSize, bool centered = false);
    void newButton(const std::string& content, const sf::Vector2u& position, unsigned int characterSize, bool centered = false);

    void newRectangle(sf::Rect<unsigned int> rect, const sf::Color& color);


    unsigned char m_selected = 0;

    std::vector<sf::Text> m_texts;

private:

    sf::VertexArray m_vertices;

    void highlightUpdate(unsigned char newSelected);

    unsigned char m_buttonsCount = 0;
    unsigned char m_escAction;

    bool m_joystickHigh = false;

    sf::Vector2f m_viewPos;


};

#endif
