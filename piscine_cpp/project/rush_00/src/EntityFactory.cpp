#include <EntityFactory.hpp>

#include <globals.hpp>
#include <game.hpp>
#include <cstdlib>

#include <ComponentRender.hpp>
#include <ComponentPlayer.hpp>
#include <ComponentMove.hpp>
#include <ComponentCollisionBox.hpp>
#include <ComponentEnemy.hpp>

unsigned int 	EF::s_score;
const char*		EF::s_str;

static void		player(Entity* e)
{
	e->addComponent(new ComponentRender(">", ComponentRender::Player));
	e->addComponent(new ComponentPlayer);
	e->addComponent(new ComponentMove);
	e->addComponent(new ComponentCollisionBox(Vector2f(.9f, .9f)));
}

static void		bullet(Entity* e)
{
	ComponentMove* 	m = new ComponentMove();
	m->setMove(BULLET_SPEED_VECTORF);
	e->addComponent(new ComponentRender("-", ComponentRender::Bullet));
	e->addComponent(m);
	e->addComponent(new ComponentCollisionBox(BULLET_BOX_VECTORF));
}

static void 	enemy(Entity* e)
{
	float 	speed = 5 + static_cast<int>(EF::s_score / 10);
	speed = speed > ENEMY_SPEED_LIMITE ? ENEMY_SPEED_LIMITE : speed;
	ComponentMove* 	m = new ComponentMove();
	m->setMove(Vector2f(static_cast<float>(-speed), 0.f));
	e->addComponent(new ComponentRender("<", ComponentRender::Enemy));
	e->addComponent(new ComponentEnemy(ComponentEnemy::Enemy1, EF::s_score / 5 + 1));
	e->addComponent(m);
	e->addComponent(new ComponentCollisionBox(Vector2f(.9f, .9f)));
}

static void 	background(Entity* e)
{
	const char*		backgrounds[] =
	{
			"~",
			".",
			"+"
	};
	ComponentMove* 	m = new ComponentMove();
	m->setMove(BACKGROUND_SPEED_VECTORF);
	e->addComponent(new ComponentRender(backgrounds[
					static_cast<unsigned int>(std::rand())
					% (sizeof(backgrounds)/sizeof(*backgrounds))
			], ComponentRender::Background));
	e->addComponent(m);
}

static void		gameOver(Entity* e)
{
	e->addComponent(new ComponentRender(EF::s_str,
				(EF::s_str == GAMEOVER_STR) ? ComponentRender::MenuTitle : ComponentRender::MenuChoice));
}

static void		gameOverSel(Entity* e)
{
	e->addComponent(new ComponentRender(">>>", ComponentRender::MenuTitle));
}

static void 	enemybullet(Entity* e)
{
	ComponentMove* 	m = new ComponentMove();
	m->setMove(ENNEMY_BULLET_SPEED_VECTORF);
	e->addComponent(new ComponentRender("-", ComponentRender::EnemyBullet));
	e->addComponent(m);
	e->addComponent(new ComponentCollisionBox(BULLET_BOX_VECTORF));
}

Entity*		EF::build(const Vector2f& pos, Who who)
{
	void (*builders[EF::COUNT])(Entity*) =
	{
		player,
		bullet,
		enemy,
		background,
		gameOver,
		gameOverSel,
		enemybullet
	};

	Entity*		e = new Entity(pos);

	builders[who](e);

	return e;
}
