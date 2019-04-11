#include <SystemPhysics.hpp>
#include <globals.hpp>
#include <Scene.hpp>
#include <ComponentPlayer.hpp>
#include <ComponentEnemy.hpp>
#include <EntityFactory.hpp>

#include <cmath>

SystemPhysics::SystemPhysics()
{
}

SystemPhysics::~SystemPhysics()
{
}

int		SystemPhysics::init(Scene* scene)
{
	m_scene = scene;
	return 0;
}

static int	boxesCollide(const Vector2f& bp1, const Vector2f& b1,
							const Vector2f& bp2, const Vector2f& b2)
{
	if (bp1.x - b1.x < bp2.x + b2.x && bp1.x + b1.x > bp2.x - b2.x)
	{
		if (bp1.y - b1.y < bp2.y + b2.y && bp1.y + b1.y > bp2.y - b2.y)
			return 1;
	}

	return 0;
}

static bool		isOutOfGame(const Vector2f& pos)
{
	return (pos.x < 0.f || pos.x >= g_gamesize.x || pos.y < 0.f || pos.y >= g_gamesize.y);
}

static void		limitToGameBounds(Vector2f& pos, Vector2f& move, const Vector2f& curPos)
{
	if (pos.x < 0.f)
	{
		move.x = .5f  - curPos.x;
		pos.x = .5f;
	}
	else if (pos.x >= g_gamesize.x)
	{
		move.x = g_gamesize.x - .5f  - curPos.x;
		pos.x = g_gamesize.x - .5f;
	}
	if (pos.y < 0.f)
	{
		move.y = .5f  - curPos.y;
		pos.y = .5f;
	}
	else if (pos.y >= g_gamesize.y)
	{
		move.y = g_gamesize.y - .5f  - curPos.y;
		pos.y = g_gamesize.y - .5f;
	}
}

int 	SystemPhysics::handleCollision(Entity* e1, Entity* e2)
{
	ComponentEnemy* c1 = e1->getComponent<ComponentEnemy>();
	ComponentEnemy* c2 = e2->getComponent<ComponentEnemy>();
	ComponentPlayer* p1 = e1->getComponent<ComponentPlayer>();
	ComponentPlayer* p2 = e2->getComponent<ComponentPlayer>();

	if ((c1 && c2) || (!c1 && !c2 && !p1 && !p2))
	{
		return 0;
	}
	else if (!c1 && c2 && !p1)
	{
		c2->setLife(c2->getLife() - 1);
		m_scene->removeEntity(e1);
		if (c2->getLife() == 0)
		{
			m_scene->removeEntity(e2);
			++EF::s_score;
			m_infoDisp.updateScore();
		}
	}
	else if (c1 && !c2 && !p2)
		return handleCollision(e2, e1);
	else
	{
		m_scene->removeEntity(e2);
		m_scene->removeEntity(e1);
	}
	return 1;
}

int		SystemPhysics::update(float elapsedTime)
{
	m_infoDisp.update(elapsedTime);

	unsigned int	i;
	Vector2f		move;
	Vector2f		pos;
	Vector2f		box;
	Vector2f		boxPos;
	bool			collided;

	for (i = 0; m_boxes[i]; ++i)
	{
		move = m_moves[i]->getMove() * elapsedTime;

		if (move != 0.f)
		{
			const Vector2f&		curPos = m_entities[i]->getPosition();
			pos = curPos + move;

			if (isOutOfGame(pos))
			{
				if (!m_entities[i]->getComponent<ComponentPlayer>())
					m_scene->removeEntity(m_entities[i]);
				limitToGameBounds(pos, move, curPos);
			}

			box = m_boxes[i]->getCollisionBox();
			boxPos = pos;
			if (move.x > box.x * 2.f)
			{
				box.x += move.x / 2;
				boxPos.x -= move.x / 2;
			}
			collided = false;
			for (unsigned int j = 0; m_boxes[j]; ++j)
			{
				if (i == j)
					continue;
				if (boxesCollide(boxPos, box, m_entities[j]->getPosition(), m_boxes[j]->getCollisionBox()))
				{
					if (handleCollision(m_entities[i], m_entities[j]))
						break;
				}
			}
			m_entities[i]->setPosition(pos);
		}

	}

	while (m_moves[i])
	{
		move = m_moves[i]->getMove() * elapsedTime;

		if (move != 0.f)
		{
			pos = m_entities[i]->getPosition() + move;

			if (isOutOfGame(pos))
				m_scene->removeEntity(m_entities[i]);
			else
				m_entities[i]->setPosition(pos);
		}
		++i;
	}

	return 1;
}

void	SystemPhysics::addEntity(Entity* entity)
{
	ComponentMove*	move = entity->getComponent<ComponentMove>();

	if (move)
	{
		ComponentCollisionBox*	box = entity->getComponent<ComponentCollisionBox>();

		if (box)
		{
			m_entities.insert(0, entity);
			m_moves.insert(0, move);
			m_boxes.insert(0, box);
		}
		else
		{
			m_entities.push_back(entity);
			m_moves.push_back(move);
		}
	}

	if (entity->getComponent<ComponentPlayer>())
	{
		m_infoDisp.init(m_scene);
	}
}

void	SystemPhysics::removeEntity(Entity* entity)
{
	ComponentMove*	move = entity->getComponent<ComponentMove>();

	if (move)
	{
		unsigned int		i = m_moves.find(move);

		m_entities.erase(i);
		m_moves.erase(i);
		if (i < m_boxes.len())
			m_boxes.erase(i);
	}

	if (entity->getComponent<ComponentPlayer>())
	{
		m_infoDisp.empty();
	}
}
