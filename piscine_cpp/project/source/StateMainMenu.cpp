#include "StateMainMenu.hpp"

#include "StatePlay.hpp"
#include "StateOptionsMenu.hpp"

#include "Vars.hpp"


MainMenuState::MainMenuState() : Menu(2)
{
    newButton("Jouer", sf::Vector2u(20,50), 30);
    newButton("Options", sf::Vector2u(20,60), 30);
    newButton("Quitter", sf::Vector2u(20,70), 30);

    newText("PROJET ISN", sf::Vector2u(50,15), 50, true);

    audioManager->playMusic("menu");
}

void MainMenuState::update()
{
    if(updateMenu())
    {
        switch(m_selected)
        {
        case 0:
            game->changeState(new PlayState);
            break;
        case 1:
            game->addState(new OptionsMenuState);
            break;
        case 2:
            game->isRunning = false;
            break;
        }
    }
}

void MainMenuState::draw()
{
    drawMenu();
}
