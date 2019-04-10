#include <GameOver.hpp>
#include <EntityFactory.hpp>
#include <input.hpp>
#include <game.hpp>

GameOver::GameOver(Scene* s) :
	m_scene(s),
	m_selEnt(EF::build(Vector2f(GAMEOVER_SEL_X, GAMEOVER_CHOICE_Y(0)), EF::GameOverSel)),
	m_choice(CLimFirst + 1)
{
	EF::s_str = GAMEOVER_STR;
	m_scene->addEntity(EF::build(GAMEOVER_POS_VEC, EF::GameOver));
	EF::s_str = GAMEOVER_RETRY_STR;
	m_scene->addEntity(EF::build(GAMEOVER_RETRY_POS_VEC, EF::GameOver));
	EF::s_str = GAMEOVER_ADMIRE_STR;
	m_scene->addEntity(EF::build(GAMEOVER_ADMIRE_POS_VEC, EF::GameOver));
	EF::s_str = GAMEOVER_QUIT_STR;
	m_scene->addEntity(EF::build(GAMEOVER_QUIT_POS_VEC, EF::GameOver));

	m_scene->addEntity(m_selEnt);
}

GameOver::~GameOver()
{
}

GameOver::Ret		GameOver::update(unsigned int inputs)
{
	if (inputs & KEYMASK(Input::SPACE))
	{
		if (m_choice == CQuit)
			return RQuit;
		m_scene->wipe();
		if (m_choice == CRetry)
			m_scene->addEntity(EF::build(PLAYER_SPAWN_POS_VEC, EF::Player));
		return RContinue;
	}

	int		move = ((inputs & KEYMASK(Input::DOWN)) != 0) - ((inputs & KEYMASK(Input::UP)) != 0);

	if (move && ((move == 1 && m_choice != CLimLast - 1) || (move == -1 && m_choice != CLimFirst + 1)))
	{
		const Vector2f&		pos = m_selEnt->getPosition();
		m_selEnt->setPosition(Vector2f(pos.x, pos.y + move * GAMEOVER_CHOICES_DIST));
		m_choice += move;
	}
	return RPending;
}
