#include "StateOptionsMenu.hpp"

#include "StateMainMenu.hpp"

#include "Vars.hpp"

#include <SFML/Window/Event.hpp>

#include <fstream>


OptionsMenuState::OptionsMenuState() : Menu(6), m_fullscreen(game->fullscreen)
{
    std::ifstream file("data/config/ctrlmap");
    for(unsigned int i = 0; std::getline(file, m_controls[i]); ++i);

    newRectangle(sf::Rect<unsigned int>(0,0,100,100), sf::Color::Black);

    newButton("avancer   " + m_controls[controls[0]], sf::Vector2u(50,20), 30, true);
    newButton("gauche   " + m_controls[controls[1]], sf::Vector2u(50,27), 30, true);
    newButton("reculer   " + m_controls[controls[2]], sf::Vector2u(50,34), 30, true);
    newButton("droite   " + m_controls[controls[3]], sf::Vector2u(50,41), 30, true);
    newButton("attaquer   " + m_controls[controls[4]], sf::Vector2u(50,48), 30, true);

    std::string Fullscreen = m_fullscreen ? "On" : "Off";
    newButton("plein ecran   " + Fullscreen, sf::Vector2u(50,60), 30, true);

    newButton("< Retour", sf::Vector2u(1,90), 30);

    newText("OPTIONS", sf::Vector2u(50,0), 50, true);
}

void OptionsMenuState::update()
{
    if(m_inputting)
    {
        for(sf::Event event; window.pollEvent(event) && event.type == sf::Event::KeyPressed;)
        {
            if(event.key.code == sf::Keyboard::Escape)
            {
                m_inputting = false;
                std::string selected = m_texts[m_selected].getString();
                selected.erase(selected.begin() + selected.size() - 1);
                selected += m_controls[controls[m_selected]];
                m_texts[m_selected].setString(selected);
            }
            else
            {
                bool available = true;
                for(unsigned char i = 0; i != 5; ++i)
                {
                    if(event.key.code == controls[i])
                    {
                        available = false;
                        break;
                    }
                }
                if(available)
                {
                    m_inputting = false;
                    std::string selected = m_texts[m_selected].getString();
                    selected.erase(selected.begin() + selected.size() - 1);
                    selected += m_controls[event.key.code];
                    m_texts[m_selected].setString(selected);
                    controls[m_selected] = event.key.code;
                }
            }
        }
    }
    else if(updateMenu())
    {
        if(m_selected == 5)
        {
            m_fullscreen = !m_fullscreen;
            std::string Fullscreen = m_fullscreen ? "On" : "Off";
            m_texts[5].setString("plein ecran   " + Fullscreen);
        }
        else if(m_selected == 6)
        {
            std::ofstream file("data/config/controls", std::ios::trunc);
            for(unsigned char i = 0; i != 5; ++i)
            {
                file << (char)controls[i];
            }
            file.close();

            if(m_fullscreen != game->fullscreen)
            {
                game->fullscreen = m_fullscreen;
                game->createWindow();

                file.open("data/config/settings", std::ios::trunc);
                file << (char)game->fullscreen;
            }

            game->popState();
        }
        else
        {
            m_inputting = true;
            std::string selected = m_texts[m_selected].getString();
            while(selected[selected.size() - 2] != ' ')
            {
                selected.erase(selected.begin() + selected.size() - 1);
            }
            selected[selected.size() - 1] = '_';
            m_texts[m_selected].setString(selected);
        }
    }
}

void OptionsMenuState::draw()
{
    drawMenu();
}
