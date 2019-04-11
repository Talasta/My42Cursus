#include <SystemEnemies.hpp>
#include <display.hpp>
#include <Entity.hpp>
#include <Scene.hpp>
#include <globals.hpp>
#include <game.hpp>
#include <EntityFactory.hpp>
#include <ComponentPlayer.hpp>
#include <cstdlib>

SystemEnemies::SystemEnemies() : m_player(NULL)
{
	srand(static_cast<unsigned int>(time(NULL)));
}

SystemEnemies::~SystemEnemies()
{
}

int		SystemEnemies::update(float elapsedTime)
{
	(void)elapsedTime;



	if (m_enemies.len() < BASE_ENEMIES_SPAWNED + (EF::s_score) / 10 && m_player)
	{
		float	x = g_gamesize.x - .5f;
		float	y = static_cast<unsigned int>(std::rand()) % g_gamesize.y + .5f;
		m_scene->addEntity(EF::build(Vector2f(x, y), EF::Enemy));
	}

	Entity**	e = m_entities;

	for (ComponentEnemy** c = m_enemies; *c; ++c)
	{
		if ((*c)->bulletTime > BULLETTIME_LIMIT_ENEMIES)
		{
			m_scene->addEntity(EF::build((*e)->getPosition() + Vector2f(BULLET_SPAWN_ENEMY_DIST, 0.f), EF::EnemyBullet));
			(*c)->bulletTime = 0;
		}
		(*c)->bulletTime += elapsedTime;
		e++;
	}

	return 1;
}

void	SystemEnemies::addEntity(Entity* entity)
{
	ComponentPlayer*	player = entity->getComponent<ComponentPlayer>();

	if (player)
	{
		m_player = entity;
	}

	ComponentEnemy*	enemies = entity->getComponent<ComponentEnemy>();

	if (enemies)
	{
		m_entities.push_back(entity);
		m_enemies.push_back(enemies);
	}
}

void	SystemEnemies::removeEntity(Entity* entity)
{
	ComponentEnemy*	enemies = entity->getComponent<ComponentEnemy>();

	if (enemies)
	{
		unsigned int	i = m_enemies.find(enemies);

		m_entities.erase(i);
		m_enemies.erase(i);
	}

	if (entity == m_player)
	{
		m_player = NULL;
	}
}

int		SystemEnemies::init(Scene* scene)
{
	m_scene = scene;
	return 0;
}
