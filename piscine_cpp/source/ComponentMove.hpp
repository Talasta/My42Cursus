#ifndef COMPONENTMOVE_HPP
#define COMPONENTMOVE_HPP

#include "Component.hpp"

#include <SFML/System/Vector2.hpp>

class Move : public Component{

public:

    static const Component::Type s_type;
    virtual Component* getCopy() const;

    Move(float speed);
    virtual void init(Entity* owner);

    virtual void receive(const Message& msg);

    Entity* getOwner() const;
    bool isMoving() const;

    const sf::Vector2f& getMove() const;
    sf::Vector2f getDirection() const;


private:

    Entity* m_owner;

    float m_speed;
    sf::Vector2f m_move;

    bool m_moving = false;

};

#endif
