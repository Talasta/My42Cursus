#include "StatePlay.hpp"

#include "Vars.hpp"


System* systems[9];
float dt;

PlayState::PlayState()
{
    eventManager = &m_eventManager;

    systems[System::ai] = &m_aiSystem;
    systems[System::animation] = &m_animationSystem;
    systems[System::physics] = &m_physicsSystem;
    systems[System::playerControl] = &m_playerControlSystem;
    systems[System::render] = &m_renderSystem;
    systems[System::script] = &m_scriptSystem;
    systems[System::spawner] = &m_spawnerSystem;
    systems[System::timer] = &m_timerSystem;
    systems[System::ui] = &m_uiSystem;

    m_scene.load("level");

    audioManager->playMusic("game");

    m_dt = std::clock();
}

void PlayState::update()
{
    dt = (std::clock() - m_dt) / (float)CLOCKS_PER_SEC;
    m_dt = std::clock();

    m_playerControlSystem.update();
    m_spawnerSystem.update();
    m_aiSystem.update();
    m_scriptSystem.update();
    m_physicsSystem.update();
    m_animationSystem.update();

    m_scene.update();
}

void PlayState::draw()
{
    m_tilemap.render();

    m_renderSystem.update();

    m_uiSystem.update();
}

void PlayState::resume()
{
    audioManager->resumeMusic();

    Message msg(0);
    msg.number = std::clock() - m_dt;
    m_timerSystem.receive(msg);

    m_dt = std::clock();
}
