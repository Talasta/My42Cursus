#ifndef SYSTEMPHYSICS_HPP
#define SYSTEMPHYSICS_HPP

#include "System.hpp"

#include "ComponentCollisionBox.hpp"
#include "ComponentCollisionBoxPlayer.hpp"
#include "ComponentMove.hpp"


class PhysicsSystem : public System{

public:

    virtual void update();

    virtual void add(Entity* entity);
    virtual void remove(Entity* entity);


private:

    std::vector<Move*> m_moves;
    std::vector<CollisionBox*> m_boxes;

    unsigned int m_movingBoxes = 0;


    CollisionBox* m_playerCollisionBox = nullptr;

    std::vector<CollisionBoxPlayer*> m_boxesPlayer;
};

#endif
