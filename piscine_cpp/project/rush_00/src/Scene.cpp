#include <Scene.hpp>

#include <SystemRender.hpp>
#include <SystemPlayerInput.hpp>
#include <SystemPhysics.hpp>
#include <SystemEnemies.hpp>
#include <display.hpp>

#include <unistd.h>

Scene::Scene() : m_entitiesLen(0)
{
	m_systems[System::PlayerInput] = new SystemPlayerInput;
	m_systems[System::Render] = new SystemRender;
	m_systems[System::Physics] = new SystemPhysics;
	m_systems[System::Enemies] = new SystemEnemies;

	m_clock = std::clock();
}

Scene::~Scene()
{
	Entity**	e;

	for (e = m_entities; *e; ++e)
		delete *e;

	for (std::size_t i = 0; i != System::COUNT; ++i)
		delete m_systems[i];
}

int		Scene::init()
{
	int 	ret;

	for (std::size_t i = 0; i != System::COUNT; ++i)
	{
		if ((ret = m_systems[i]->init(this)))
			return ret;
	}
	return 0;
}

void	Scene::addEntity(Entity* entity)
{
	m_entities.push_back(entity);
}

void	Scene::removeEntity(Entity* entity)
{
	if (!m_entitiesToRm[m_entitiesToRm.find(entity)])
		m_entitiesToRm.push_back(entity);
}

int		Scene::update()
{
	std::clock_t	clock = std::clock();
	float			elapsedTime = static_cast<float>(clock - m_clock) / CLOCKS_PER_SEC;

	m_clock = clock;
	if (elapsedTime < MIN_FRAME_TIME)
	{
		usleep(static_cast<useconds_t>((MIN_FRAME_TIME - elapsedTime) * 1000000));
		elapsedTime = MIN_FRAME_TIME;
	}

	int				ret;

	for (std::size_t i = 0; i != System::COUNT; ++i)
	{
		ret = m_systems[i]->update(elapsedTime);
		if (ret <= 0)
			return ret;
	}
	return 1;
}

void	Scene::updateEntities()
{
	Array<Entity*, ENTITIES_ARRAYS_LEN>		entitiesToRm;
	unsigned int							entidx;

	while ((entitiesToRm = m_entitiesToRm)[0])
	{
		m_entitiesToRm[0] = NULL;
		for (Entity** etr = entitiesToRm; *etr; ++etr)
		{
			entidx = m_entities.find(*etr);
			if (m_entities[entidx])
			{
				m_entities.erase(entidx);
				--m_entitiesLen;

				for (unsigned int i = 0; i != System::COUNT; ++i)
					m_systems[i]->removeEntity(*etr);

				delete *etr;
			}
		}
	}

	while (m_entities[m_entitiesLen])
	{
		for (std::size_t i = 0; i != System::COUNT; ++i)
		{
			m_systems[i]->addEntity(m_entities[m_entitiesLen]);
		}
		++m_entitiesLen;
	}
}

void	Scene::wipe()
{
	for (unsigned int i = m_entitiesLen; m_entities[i]; ++i)
		delete m_entities[i];
	m_entities[m_entitiesLen] = NULL;

	m_entitiesToRm = m_entities;
}
