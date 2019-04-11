#ifndef SYSTEMAI_HPP
#define SYSTEMAI_HPP

#include "System.hpp"

#include "ComponentAI.hpp"

class AISystem : public System{

public:

    AISystem();

    virtual void update();

    virtual void add(Entity* entity);

    virtual void remove(Entity* entity);


private:

    std::vector<Entity*> m_entities;;

    std::vector<bool> m_map;

    Path* pathFind(const sf::Vector2f& basePos, const sf::Vector2f& destinationPos);

    Entity* m_player = nullptr;
};

#endif
