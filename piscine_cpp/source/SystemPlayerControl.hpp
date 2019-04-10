#ifndef SYSTEMPLAYERCONTROL_HPP
#define SYSTEMPLAYERCONTROL_HPP

#include "System.hpp"
#include "ComponentPlayerControl.hpp"

#include <SFML/Window/Keyboard.hpp>


class PlayerControlSystem : public System{

public:

    PlayerControlSystem();

    virtual void update();

    virtual void add(Entity* entity);
    virtual void remove(Entity* entity);

    virtual void receive(const Message& msg);


private:

    enum { forward = 0, left, backward, right, use };
    sf::Keyboard::Key m_keys[5];

    Entity* m_player;

    void pause() const;

    unsigned int m_score = 0;
    unsigned int m_combo = 0;
    unsigned char m_shotsSinceLastTouch = 0;
};

#endif
