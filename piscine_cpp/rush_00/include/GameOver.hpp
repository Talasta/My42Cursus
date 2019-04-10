#ifndef GAMEOVER_HPP
#define GAMEOVER_HPP

#include "Scene.hpp"

class	GameOver
{
public:

	enum Ret
	{
		RQuit = 0,
		RContinue,
		RPending = 42
	};

	enum Choice
	{
		CLimFirst,
		CRetry,
		CAdmire,
		CQuit,
		CLimLast
	};

	GameOver(Scene*);
	~GameOver();

	Ret		update(unsigned int inputs);

private:

	GameOver(const GameOver&);
	GameOver& operator=(const GameOver&);

	Scene*		m_scene;
	Entity*		m_selEnt;
	int			m_choice;

	char _pad[4];
};

#endif
