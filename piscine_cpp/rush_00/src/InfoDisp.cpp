#include <InfoDisp.hpp>
#include <EntityFactory.hpp>
#include <globals.hpp>
#include <game.hpp>

#include <sstream>

InfoDisp::InfoDisp() : m_scoreRender(NULL)
{
}

InfoDisp::~InfoDisp()
{
}

void	InfoDisp::init(Scene* scene)
{
	m_elapsedTime = 0.f;

	Entity*		e;

	e = new Entity(Vector2f(0.f, g_gamesize.y + UI_HEIGHT - 1));
	m_scoreRender = new ComponentRender("", ComponentRender::MenuChoice);
	e->addComponent(m_scoreRender);
	scene->addEntity(e);
	updateScore();

	e = new Entity(Vector2f(0.f, g_gamesize.y + UI_HEIGHT - 3));
	m_timeRender = new ComponentRender("", ComponentRender::MenuChoice);
	e->addComponent(m_timeRender);
	scene->addEntity(e);
}

void	InfoDisp::update(float elapsedTime)
{
	if (m_scoreRender)
	{
		m_elapsedTime += elapsedTime;

		std::ostringstream	oss;
		oss.setf(std::ios::fixed, std::ios::floatfield);
		oss.precision(1);
		oss << m_elapsedTime;
		m_timeRender->setRepr(oss.str().c_str());
	}
}

void	InfoDisp::updateScore()
{
	std::ostringstream	oss;
	oss << "Score: " << EF::s_score;
	m_scoreRender->setRepr(oss.str().c_str());
}

void	InfoDisp::empty()
{
	m_scoreRender = NULL;
	EF::s_score = 0;
}
