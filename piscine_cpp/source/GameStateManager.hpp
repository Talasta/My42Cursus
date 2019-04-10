#ifndef GAMESTATEMANAGER_HPP
#define GAMESTATEMANAGER_HPP

#include "GameState.hpp"

#include "AudioManager.hpp"

#include <SFML/Graphics/Text.hpp>


class GameStateManager{

public:

    GameStateManager();
    ~GameStateManager();

    void update();
    void draw();

    void changeState(GameState* state);
    void addState(GameState* state);
    void popState();

    void createWindow();
    void resizeWindow();
    bool fullscreen;

    bool isRunning = true;

    sf::Font font;

private:

    AudioManager m_audioManager;

    std::vector<GameState*> m_states;
};


#endif
