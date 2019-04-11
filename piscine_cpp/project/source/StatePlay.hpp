#ifndef STATEPLAYING_HPP
#define STATEPLAYING_HPP

#include "GameState.hpp"

#include "EntityFactory.hpp"
#include "EventManager.hpp"
#include "Scene.hpp"

#include "Tilemap.hpp"

#include "SystemAI.hpp"
#include "SystemAnimation.hpp"
#include "SystemPhysics.hpp"
#include "SystemPlayerControl.hpp"
#include "SystemRender.hpp"
#include "SystemScript.hpp"
#include "SystemSpawner.hpp"
#include "SystemTimer.hpp"
#include "SystemUI.hpp"


class PlayState : public GameState{

public:

    PlayState();

    virtual void update();

    virtual void draw();

    virtual void resume();


private:

    EntityFactory m_entityFactory;
    EventManager m_eventManager;
    Scene m_scene;

    Tilemap m_tilemap;

    AISystem m_aiSystem;
    AnimationSystem m_animationSystem;
    PhysicsSystem m_physicsSystem;
    PlayerControlSystem m_playerControlSystem;
    RenderSystem m_renderSystem;
    ScriptSystem m_scriptSystem;
    SpawnerSystem m_spawnerSystem;
    TimerSystem m_timerSystem;
    UISystem m_uiSystem;

    long int m_dt;
};


#endif
