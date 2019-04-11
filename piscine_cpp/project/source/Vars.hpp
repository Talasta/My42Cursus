#ifndef VARS_HPP
#define VARS_HPP

#include "GameStateManager.hpp"

#include "System.hpp"
#include "EntityFactory.hpp"
#include "EventManager.hpp"
#include "Scene.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/Keyboard.hpp>


#define WINDOW_RATIO_X 6.4f
#define WINDOW_RATIO_Y 3.6f


extern GameStateManager* game;
extern AudioManager* audioManager;

extern System* systems[9];

extern EntityFactory* entityFactory;
extern EventManager* eventManager;
extern Scene* currentScene;

extern sf::RenderWindow window;

extern sf::Keyboard::Key controls[5];

extern float dt;


#endif
