#include "StatePauseMenu.hpp"

#include "StateMainMenu.hpp"
#include "StateOptionsMenu.hpp"

#include "Vars.hpp"


PauseMenuState::PauseMenuState() : Menu(0)
{
    newButton("Continuer", sf::Vector2u(50,40), 30, true);
    newButton("Options", sf::Vector2u(50,50), 30, true);
    newButton("Quitter", sf::Vector2u(50,60), 30, true);

    newText("PAUSE", sf::Vector2u(50,10), 50, true);

    newRectangle(sf::Rect<unsigned int>(0,0,100,100), sf::Color(0,0,0,128));
}

void PauseMenuState::update()
{
    if(updateMenu())
    {
        switch(m_selected)
        {
        case 0:
            game->popState();
            break;
        case 1:
            game->addState(new OptionsMenuState);
            break;
        case 2:
            game->changeState(new MainMenuState);
            break;
        }
    }
}

void PauseMenuState::draw()
{
    drawMenu();
}
