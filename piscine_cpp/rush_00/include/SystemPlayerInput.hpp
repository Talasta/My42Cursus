#ifndef SYSTEMPLAYERINPUT_HPP
#define SYSTEMPLAYERINPUT_HPP

#include "System.hpp"
#include "ComponentMove.hpp"
#include "GameOver.hpp"

class	SystemPlayerInput : public System
{
public:

	SystemPlayerInput();
	virtual ~SystemPlayerInput();

	virtual int		init(Scene*);
	virtual int		update(float elapsedTime);

	virtual void	addEntity(Entity*);
	virtual void	removeEntity(Entity*);

private:

	SystemPlayerInput(const SystemPlayerInput&);
	SystemPlayerInput& operator=(const SystemPlayerInput&);

	int				processInput(unsigned int inputs, float elapsedTime);

	Scene*			m_scene;
	Entity*			m_player;
	ComponentMove*	m_playerMove;
	float			m_bulletTime;
	bool			m_shooting;

	char _pad[3];

	GameOver*		m_gameOver;
};

#endif
