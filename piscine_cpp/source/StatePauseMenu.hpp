#ifndef STATEPAUSEMENU_HPP
#define STATEPAUSEMENU_HPP

#include "GameState.hpp"
#include "Menu.hpp"

class PauseMenuState : public GameState, public Menu{

public:

    PauseMenuState();

    virtual void update();

    virtual void draw();

};

#endif
