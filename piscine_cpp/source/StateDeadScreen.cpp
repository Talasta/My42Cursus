#include "StateDeadScreen.hpp"

#include "StateMainMenu.hpp"
#include "StatePlay.hpp"

#include "Operations.hpp"

#include "Vars.hpp"

#include <fstream>


DeadScreenState::DeadScreenState(unsigned int score) : Menu(1)
{
    audioManager->pauseMusic();
    audioManager->playSound("endGame");

    newRectangle(sf::Rect<unsigned int>(0,0,100,100), sf::Color(0,0,0,128));

    newButton("Recommencer", sf::Vector2u(50, 60), 40, true);
    newButton("Menu principal", sf::Vector2u(50,70), 40, true);

    newText("VOUS ETES MORT !", sf::Vector2u(50, 5), 50, true);

    std::stringstream scoreString;
    scoreString << score;
    newText("Score: " + scoreString.str(), sf::Vector2u(50, 30), 30, true);

    std::fstream file("data/config/stats", std::ios::in);
    std::string highScoreString;
    std::getline(file, highScoreString);

    unsigned int highScore = toNumber(highScoreString);

    std::string highScoreText;

    if(score > highScore)
    {
        file.close();
        file.open("data/config/stats", std::ios::out | std::ios::trunc);
        file << score;
        highScoreText = "Nouveau meilleur score !";
    }
    else
    {
        highScoreText = "Meilleur score: " + highScoreString;
    }

    newText(highScoreText, sf::Vector2u(50,37), 30, true);
}

void DeadScreenState::update()
{
    if(updateMenu())
    {
        switch(m_selected)
        {
        case 0:
            game->changeState(new PlayState);
            break;

        case 1:
            game->changeState(new MainMenuState);
            break;
        }
    }
}

void DeadScreenState::draw()
{
    drawMenu();
}
