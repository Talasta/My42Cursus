#ifndef STATEMENUMAIN_HPP
#define STATEMENUMAIN_HPP

#include "GameState.hpp"
#include "Menu.hpp"

class MainMenuState : public GameState, public Menu{

public:

    MainMenuState();

    virtual void update();

    virtual void draw();
};

#endif
