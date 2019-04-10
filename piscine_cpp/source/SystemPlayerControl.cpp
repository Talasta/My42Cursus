#include "SystemPlayerControl.hpp"

#include "StatePauseMenu.hpp"
#include "StateDeadScreen.hpp"

#include "ComponentAI.hpp"

#include "Vars.hpp"

#include <SFML/Window/Event.hpp>

#include <fstream>

#include <iostream>
PlayerControlSystem::PlayerControlSystem()
{
    std::ifstream file("data/config/controls");

    std::string controls;
    std::getline(file, controls);

    for(unsigned int i = 0; i != 5; ++i)
    {
        m_keys[i] = (sf::Keyboard::Key)(controls[i]);
    }

    eventManager->listenToEvent(this, "enemyHit");
    eventManager->listenToEvent(this, "playerShot");
}

void PlayerControlSystem::update()
{
    for(sf::Event event; window.pollEvent(event);)
    {
        switch(event.type)
        {
        case sf::Event::KeyPressed: case sf::Event::KeyReleased:

            if(event.key.code == controls[forward] || event.key.code == controls[backward] || event.key.code == controls[left] || event.key.code == controls[right])
            {
                Message msg(Message::MSetMove);
                msg.vector = sf::Vector2f(sf::Keyboard::isKeyPressed(controls[right]) - sf::Keyboard::isKeyPressed(controls[left]),
                                          sf::Keyboard::isKeyPressed(controls[backward]) - sf::Keyboard::isKeyPressed(controls[forward]));
                m_player->receive(msg);
            }
            else if(event.key.code == controls[use])
            {
                Message msg(Message::MUse);
                msg.number = sf::Keyboard::isKeyPressed(controls[use]);
                m_player->receive(msg);
            }
            else if(event.key.code == sf::Keyboard::Escape && event.type == sf::Event::KeyPressed)
            {
                pause();
            }
            break;

        case sf::Event::JoystickMoved:

            if(event.joystickMove.axis < 2)
            {
                sf::Vector2f joystickAxis(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));

                Message msg(Message::MSetMove);
                msg.vector.x = std::abs(joystickAxis.x) > 50 ? (joystickAxis.x > 0) - (joystickAxis.x < 0) : 0;
                msg.vector.y = std::abs(joystickAxis.y) > 50 ? (joystickAxis.y > 0) - (joystickAxis.y < 0) : 0;
                m_player->receive(msg);
            }
            break;

        case sf::Event::JoystickButtonPressed: case sf::Event::JoystickButtonReleased:

            if(event.joystickButton.button == 0)
            {
                Message msg(Message::MUse);
                msg.number = sf::Joystick::isButtonPressed(0,0);
                m_player->receive(msg);
            }
            else if(event.joystickButton.button == 7)
            {
                pause();
            }

        case sf::Event::Resized:
            game->resizeWindow();
            break;

        case sf::Event::Closed:
            game->isRunning = false;
            break;
        }
    }
}

void PlayerControlSystem::pause() const
{
    Message msg(Message::MSetMove);
    msg.vector = sf::Vector2f(0,0);
    m_player->receive(msg);

    msg.type = Message::MUse;
    msg.number = 0;
    m_player->receive(msg);

    audioManager->pauseMusic();
    audioManager->playSound("menuClick");

    game->addState(new PauseMenuState);
}

void PlayerControlSystem::add(Entity* entity)
{
    if(entity->getComponent<PlayerControl>())
    {
        m_player = entity;
    }
}

void PlayerControlSystem::remove(Entity* entity)
{
    if(entity == m_player)
    {
        game->addState(new DeadScreenState(m_score));
    }
}

void PlayerControlSystem::receive(const Message& msg)
{
    if(msg.type == Message::MEventCallback)
    {
        if(msg.string == "enemyHit")
        {
            m_score += 10;

            if(m_shotsSinceLastTouch == 1)
            {
                m_score += m_combo;
            }
            else
            {
                m_combo = 0;
            }

            ++m_combo;

            m_shotsSinceLastTouch = 0;

            Message message(Message::MEventCallback);
            message.number = m_score;

            eventManager->triggerEvent("scoreChanged", message);
        }
        else
        {
            ++m_shotsSinceLastTouch;
        }
    }
    else
    {
        m_combo = 0;
    }
}
