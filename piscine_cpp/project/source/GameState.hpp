#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

class GameState{

public:

    virtual ~GameState(){}

    virtual void update() = 0;
    virtual void draw() = 0;

    virtual void resume(){}
};

#endif
