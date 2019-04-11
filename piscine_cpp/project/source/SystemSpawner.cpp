#include "SystemSpawner.hpp"

#include "Vars.hpp"

#include "Operations.hpp"

#define DELAY_BETWEEN_SPAWN .5f
#define DELAY_BETWEEN_WAVE 3

#define POWERUP_PROBABILITY 20

#define getEnemyCount(waveNb) (waveNb * waveNb - waveNb +1)


SpawnerSystem::SpawnerSystem()
{
    m_powerUps[0] = "Health";
}

void SpawnerSystem::update()
{
    if(m_remainingEnemiesToSpawn != 0)
    {
        m_counter -= dt;
        if(m_counter < 0)
        {
            currentScene->add(entityFactory->createEntity("enemy", m_spawners[(unsigned int)(std::rand() / dt) % m_spawners.size()]));

            --m_remainingEnemiesToSpawn;

            m_counter = DELAY_BETWEEN_SPAWN;
        }
    }

}

void SpawnerSystem::add(Entity* entity)
{
    if(entity->getComponent<Spawner>())
    {
        m_spawners.push_back(entity->getPosition());
    }
}

void SpawnerSystem::remove(Entity* entity)
{

}

void SpawnerSystem::receive(const Message& msg)
{
    unsigned int rand = std::rand();
    if((rand % POWERUP_PROBABILITY) == 0)
    {
        currentScene->add(entityFactory->createEntity("powerUp" + m_powerUps[0], msg.vector));
    }
    Message message(Message::MEventCallback);

    if(msg.number == 0 && m_remainingEnemiesToSpawn == 0)
    {
        ++m_currentWave;
        m_counter = DELAY_BETWEEN_WAVE;

        m_remainingEnemiesToSpawn = getEnemyCount(m_currentWave);

        message.number = m_currentWave;
        eventManager->triggerEvent("waveChanged", message);
    }

    message.number = m_remainingEnemiesToSpawn + msg.number;
    eventManager->triggerEvent("enemiesRemaining", message);
}
