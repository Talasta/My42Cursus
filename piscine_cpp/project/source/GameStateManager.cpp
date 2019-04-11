#include "GameStateManager.hpp"
#include "StatePlay.hpp"
#include "StateMainMenu.hpp"

#include <SFML/Window/Keyboard.hpp>

#include <ctime>
#include <fstream>

#include "Vars.hpp"


GameStateManager* game;

sf::RenderWindow window;
bool fullscreen;

sf::Keyboard::Key controls[5];


GameStateManager::GameStateManager()
{
    game = this;
    font.loadFromFile("data/font.ttf");

    std::ifstream file("data/config/controls");

    for(unsigned char i = 0; i != 5; ++i)
    {
        controls[i] = sf::Keyboard::Key(file.get());
    }

    file.close();

    file.open("data/config/settings");
    fullscreen = file.get();

    createWindow();

    m_states.push_back(new MainMenuState);
}

GameStateManager::~GameStateManager()
{

}

void GameStateManager::update()
{
    m_states[0]->update();
}

void GameStateManager::draw()
{
    window.clear();

    for(unsigned char i = m_states.size(); --i != 255;)
    {
        m_states[i]->draw();
    }

    window.display();
}

void GameStateManager::changeState(GameState* state)
{
    for(GameState* state : m_states)
    {
        delete state;
    }

    m_states.clear();
    m_states.push_back(state);
}

void GameStateManager::addState(GameState* state)
{
    m_states.insert(m_states.begin(), state);
}

void GameStateManager::popState()
{
    delete m_states[0];
    m_states.erase(m_states.begin());
    m_states[0]->resume();
}

void GameStateManager::createWindow()
{
    sf::VideoMode videoMode = fullscreen ? sf::VideoMode::getFullscreenModes()[0] : sf::VideoMode::getDesktopMode();
    unsigned char style = fullscreen ? sf::Style::Fullscreen : sf::Style::Default;

    sf::Vector2f viewCenter(window.getView().getCenter());

    window.create(videoMode, "mon jeu", style);

    window.setView(sf::View(sf::FloatRect(viewCenter.x - WINDOW_RATIO_X * 50, viewCenter.y - WINDOW_RATIO_Y * 50, WINDOW_RATIO_X * 100, WINDOW_RATIO_Y * 100)));
    window.setMouseCursorVisible(false);
    window.setKeyRepeatEnabled(false);
    window.setJoystickThreshold(1);

    resizeWindow();
}

void GameStateManager::resizeWindow()
{
    float w = window.getSize().x;
    float h = window.getSize().y;
    float ratio = w/h;

    if(ratio == 16/9.f)
    {
        return;
    }

    sf::View view = window.getView();

    if(ratio < 16/9.f)
    {
        float decal = (h - (w * 9 / 16)) / 2 / h;
        view.setViewport(sf::FloatRect(0, decal, 1, 1 - 2 * decal));
    }
    else
    {
        float decal = (w - (h * 16 / 9)) / 2 / w;
        view.setViewport(sf::FloatRect(decal, 0, 1 - 2 * decal, 1));
    }

    window.setView(view);
}
