#ifndef INFODISP_HPP
#define INFODISP_HPP

#include "Scene.hpp"
#include "ComponentRender.hpp"

class	InfoDisp
{

public:

	InfoDisp();
	~InfoDisp();

	void	init(Scene*);
	void	empty();

	void	update(float elapsedTime);
	void	updateScore();

private:

	InfoDisp(const InfoDisp&);
	InfoDisp& operator=(const InfoDisp&);

	float				m_elapsedTime;

	char _pad[4];

	ComponentRender*	m_scoreRender;
	ComponentRender*	m_timeRender;
};

#endif
