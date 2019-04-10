#include "Menu.hpp"

#include "Vars.hpp"

#include <SFML/Window/Event.hpp>


Menu::Menu(unsigned char escAction) : m_escAction(escAction), m_viewPos(window.getView().getCenter() - window.getView().getSize() / 2.f)
{
    m_vertices.setPrimitiveType(sf::Quads);
}

bool Menu::updateMenu()
{
    bool buttonClicked = false;

    for(sf::Event event; window.pollEvent(event);)
    {
        switch(event.type)
        {

        case sf::Event::KeyPressed:
            if(event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::Up)
            {
                signed char newSelected = m_selected + (event.key.code == sf::Keyboard::Down) * 2 - 1;
                if(newSelected != -1 && newSelected != m_buttonsCount)
                {
                    highlightUpdate(newSelected);
                }
            }
            else if(event.key.code == sf::Keyboard::Return)
            {
                buttonClicked = true;
            }
            else if(event.key.code == sf::Keyboard::Escape)
            {
                m_selected = m_escAction;
                buttonClicked = true;
            }
            break;

        case sf::Event::JoystickMoved:

            if(event.joystickMove.axis == sf::Joystick::Y)
            {
                if(abs(sf::Joystick::getAxisPosition(0, sf::Joystick::Y)) > 30)
                {
                    if(!m_joystickHigh)
                    {
                        m_joystickHigh = true;
                        signed char newSelected = m_selected + (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 0) * 2 - 1;
                        if(newSelected != -1 && newSelected != m_buttonsCount)
                        {
                            highlightUpdate(newSelected);
                        }
                    }
                }
                else if(m_joystickHigh)
                {
                    m_joystickHigh = false;
                }
            }
            break;

        case sf::Event::JoystickButtonPressed:

            if(event.joystickButton.button == 0)
            {
                buttonClicked = true;
            }
            break;

        case sf::Event::Resized:
            game->resizeWindow();
            break;

        case sf::Event::Closed:
            game->isRunning = false;
            break;
        }
    }

    if(buttonClicked)
    {
        audioManager->playSound("menuClick");
        return true;
    }

    return false;
}

void Menu::newText(const std::string& content, const sf::Vector2u& position, unsigned int characterSize, bool centered)
{
    m_texts.push_back(sf::Text(content, game->font, characterSize));

    unsigned int index = m_texts.size() - 1;

    m_texts[index].setPosition(sf::Vector2f(position.x * WINDOW_RATIO_X + m_viewPos.x, position.y * WINDOW_RATIO_Y + m_viewPos.y));
    if(centered)
    {
        m_texts[index].move(- m_texts[index].getGlobalBounds().width / 2, 0);
    }
}

void Menu::newButton(const std::string& content, const sf::Vector2u& position, unsigned int characterSize, bool centered)
{
    newText(content, position, characterSize, centered);
    if(++m_buttonsCount == 1)
    {
        m_texts[0].setColor(sf::Color::Red);
    }
}

void Menu::newRectangle(sf::Rect<unsigned int> rect, const sf::Color& color)
{
    unsigned int index = m_vertices.getVertexCount();
    m_vertices.resize(m_vertices.getVertexCount() + 4);

    m_vertices[index] = sf::Vertex(sf::Vector2f(rect.left * WINDOW_RATIO_X + m_viewPos.x, rect.top * WINDOW_RATIO_Y + m_viewPos.y), color);
    m_vertices[index + 1] = sf::Vertex(sf::Vector2f((rect.left + rect.width) * WINDOW_RATIO_X + m_viewPos.x, rect.top * WINDOW_RATIO_Y + m_viewPos.y), color);
    m_vertices[index + 2] = sf::Vertex(sf::Vector2f((rect.left + rect.width) * WINDOW_RATIO_X + m_viewPos.x, (rect.top + rect.height) * WINDOW_RATIO_Y + m_viewPos.y), color);
    m_vertices[index + 3] = sf::Vertex(sf::Vector2f(rect.left * WINDOW_RATIO_X + m_viewPos.x, (rect.top + rect.height) * WINDOW_RATIO_Y + m_viewPos.y), color);
}

void Menu::highlightUpdate(unsigned char newSelected)
{
    m_texts[m_selected].setColor(sf::Color::White);
    m_texts[newSelected].setColor(sf::Color::Red);
    m_selected = newSelected;

    audioManager->playSound("menuNav");
}

void Menu::drawMenu() const
{
    window.draw(m_vertices);

    for(const auto& text : m_texts)
    {
        window.draw(text);
    }
}
