#ifndef STATEDEADSCREEN_HPP
#define STATEDEADSCREEN_HPP

#include "GameState.hpp"
#include "Menu.hpp"

class DeadScreenState : public GameState, public Menu{

public:

    DeadScreenState(unsigned int score);

    virtual void update();

    virtual void draw();
};

#endif
