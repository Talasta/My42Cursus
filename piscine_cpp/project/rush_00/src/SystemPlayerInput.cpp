#include <SystemPlayerInput.hpp>
#include <ncurses.h>
#include <Scene.hpp>
#include <ComponentPlayer.hpp>
#include <error.hpp>
#include <input.hpp>
#include <EntityFactory.hpp>
#include <globals.hpp>
#include <game.hpp>

#include <cstdio>
#include <sys/select.h>
#include <sys/ioctl.h>
#include <termios.h>

SystemPlayerInput::SystemPlayerInput() : m_player(NULL), m_bulletTime(0.f), m_shooting(false), m_gameOver(NULL)
{
}

SystemPlayerInput::~SystemPlayerInput()
{
}

int		SystemPlayerInput::init(Scene* scene)
{
	m_scene = scene;
	return 0;
}

int		SystemPlayerInput::update(float elapsedTime)
{
	int				ret;
	unsigned int 	inputs = 0;

	while ((ret = getch()) != ERR)
	{
		switch (ret)
		{
			case 'q':
				return 0;
			case KEY_UP:
			case 'w':
				inputs |= KEYMASK(Input::UP);
				break;
			case KEY_DOWN:
			case 's':
				inputs |= KEYMASK(Input::DOWN);
				break;
			case KEY_LEFT:
			case 'a':
				inputs |= KEYMASK(Input::LEFT);
				break;
			case KEY_RIGHT:
			case 'd':
				inputs |= KEYMASK(Input::RIGHT);
				break;
			case ' ':
				inputs |= KEYMASK(Input::SPACE);
				break;
			case KEY_ENTER:
				inputs |= KEYMASK(Input::ENTER);
				break;
		}
	}
	return processInput(inputs, elapsedTime);
}

int		SystemPlayerInput::processInput(unsigned int inputs, float elapsedTime)
{
	if (m_player)
	{
		Vector2f	move(0.f, 0.f);

		if (inputs & DIRKEYMASK)
		{
			Vector2f	pos = m_player->getPosition();
			float		mov = 1.f / elapsedTime;

			if (inputs & KEYMASK(Input::UP))
				move.y = -mov;
			if (inputs & KEYMASK(Input::DOWN))
				move.y += mov;
			if (inputs & KEYMASK(Input::LEFT))
				move.x = -mov;
			if (inputs & KEYMASK(Input::RIGHT))
				move.x += mov;
		}
		m_playerMove->setMove(move);

		if (inputs & KEYMASK(Input::SPACE))
			m_shooting = !m_shooting;
		if (m_shooting && m_bulletTime > BULLETTIME_LIMIT)
		{
			if (EF::s_score > 30)
			{
				m_scene->addEntity(EF::build(m_player->getPosition() + Vector2f(BULLET_SPAWN_PLAYER_DIST, -1.f), EF::Bullet));
				m_scene->addEntity(EF::build(m_player->getPosition() + Vector2f(BULLET_SPAWN_PLAYER_DIST, 0.f), EF::Bullet));
				m_scene->addEntity(EF::build(m_player->getPosition() + Vector2f(BULLET_SPAWN_PLAYER_DIST, 1.f), EF::Bullet));
			}
			else
				m_scene->addEntity(EF::build(m_player->getPosition() + Vector2f(BULLET_SPAWN_PLAYER_DIST, 0.f), EF::Bullet));
			m_bulletTime = 0;
		}
		m_bulletTime += elapsedTime;
	}
	else if (m_gameOver && inputs)
	{
		GameOver::Ret		ret = m_gameOver->update(inputs);
		
		if (ret != GameOver::RPending)
		{
			delete m_gameOver;
			m_gameOver = NULL;
			return ret;
		}
	}

	return 1;
}

void	SystemPlayerInput::addEntity(Entity* entity)
{
	ComponentPlayer*	player = entity->getComponent<ComponentPlayer>();

	if (player)
	{
		m_player = entity;
		m_playerMove = entity->getComponent<ComponentMove>();
	}
}

void	SystemPlayerInput::removeEntity(Entity* entity)
{
	if (entity == m_player)
	{
		m_player = NULL;
		m_scene->wipe();
		m_gameOver = new GameOver(m_scene);
	}
}
