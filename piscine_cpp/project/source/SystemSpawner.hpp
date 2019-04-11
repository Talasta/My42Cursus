#ifndef SYSTEMSPAWNER_HPP
#define SYSTEMSPAWNER_HPP

#include "System.hpp"

#include "ComponentSpawner.hpp"


class SpawnerSystem : public System{

public:

    SpawnerSystem();

    virtual void update();

    virtual void add(Entity* entity);
    virtual void remove(Entity* entity);

    virtual void receive(const Message& msg);


private:

    std::vector<sf::Vector2f> m_spawners;

    unsigned int m_currentWave = 1;
    unsigned int m_remainingEnemiesToSpawn = 1;

    float m_counter = 0;

    std::string m_powerUps[1];
};

#endif
