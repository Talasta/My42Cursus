#ifndef STATEOPTIONSMENU_HPP
#define STATEOPTIONSMENU_HPP

#include "GameState.hpp"
#include "Menu.hpp"

class OptionsMenuState : public GameState, public Menu{

public:

    OptionsMenuState();

    virtual void update();

    virtual void draw();


private:

    bool m_inputting = false;
    bool m_fullscreen;

    std::string m_controls[101];

};

#endif
