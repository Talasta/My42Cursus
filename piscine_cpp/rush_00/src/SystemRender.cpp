#include <SystemRender.hpp>
#include <error.hpp>
#include <display.hpp>
#include <globals.hpp>
#include <EntityFactory.hpp>
#include <game.hpp>

#include <unistd.h>
#include <ncurses.h>
#include <sys/ioctl.h>
#include <iostream>

Vector2u	g_gamesize;

SystemRender::SystemRender() : m_window(NULL), m_countBackgrounds(0)
{
}

SystemRender::~SystemRender()
{
	endwin(); // Close window
}

int		SystemRender::backgroundRegenerate()
{

	return 1;
}

int		SystemRender::update(float elapsedTime)
{
	(void)elapsedTime;
	Entity**	e = m_entities;
	int			ret = OK;
	m_countBackgrounds = 0;

	if (m_window && wclear(m_window) == ERR)
		return Err::_15;
	if (wattron(m_window, COLOR_PAIR(4)) == ERR)
        return Err::_17;
	if (wattroff(m_window, COLOR_PAIR(4)) == ERR)
        return Err::_18;

	int	t = -1;
	for (ComponentRender** r = m_renders; *r; ++r)
	{
		if ((*r)->getLayer() != t)
		{
			t = static_cast<int>((*r)->getLayer());
			if (t > 0)
			{
				if (wattroff(m_window, COLOR_PAIR(t)) == ERR)
					return Err::_18;
			}
			if (wattron(m_window, COLOR_PAIR(t + 1)) == ERR)
				return Err::_17;
		}
		// # TODO: Find more elegant way to handle this ?
		if ((*r)->getLayer() == t && t == ComponentRender::Background)
			++m_countBackgrounds;
		if ((*r)->getLayer() == t && (ret = draw((*e)->getPosition(), *r)) != 0)
			return ret;
		e++;
	}
	if (wattroff(m_window, COLOR_PAIR(t + 1)) == ERR)
		return Err::_18;

	if ((ret = wrefresh(m_window)) == ERR)
		return Err::_13;

	unsigned int nbToSpawn = static_cast<unsigned int>(std::rand() % 2);
	for (unsigned int i = m_countBackgrounds; i < MAX_IN_BACKGROUND && i < nbToSpawn + m_countBackgrounds; ++i)
	{
		float	x = g_gamesize.x - .5f;
		float	y = static_cast<unsigned int>(std::rand()) % g_gamesize.y + .5f;
		m_scene->addEntity(EF::build(Vector2f(x, y), EF::Background));
	}

	return 1;
}

void	SystemRender::addEntity(Entity* entity)
{
	ComponentRender*	render = entity->getComponent<ComponentRender>();

	if (render)
	{
		unsigned int	i;

		for (i = 0; m_renders[i] && m_renders[i]->getLayer() < render->getLayer(); ++i)
			;
		m_entities.insert(i, entity);
		m_renders.insert(i, render);
	}
}

void	SystemRender::removeEntity(Entity* entity)
{
	ComponentRender*	render = entity->getComponent<ComponentRender>();

	if (render)
	{
		unsigned int		i = m_renders.find(render);

		m_entities.erase(i);
		m_renders.erase(i);
	}
}

int		SystemRender::init(Scene* scene)
{
	int		ret;

	m_scene = scene;

	if (initscr() == NULL)
        return Err::_1;
	if (start_color() == ERR)
        return Err::_16;
	if (cbreak() == ERR)
		return Err::_2;
	if (keypad(stdscr, TRUE) == ERR)
		return Err::_3;
	if (noecho() == ERR)
		return Err::_4;
	if (curs_set(0) == ERR)
		return Err::_5;
	if (nodelay(stdscr, TRUE) == ERR)
		return Err::_6;
	if (clear() == ERR)
		return Err::_7;
	if (refresh() == ERR)
		return Err::_9;
	if ((ret = updateSizeWindow()) < 0)
		return ret;
	m_window = newwin(static_cast<int>(m_winsize.y + 2), static_cast<int>(m_winsize.x + 2), 0, 0);


	init_color(COLOR_BLUE, 230, 230, 230);
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(5, COLOR_GREEN, COLOR_BLACK);
	init_pair(6, COLOR_YELLOW, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);

	return 0;
}

int  	SystemRender::updateSizeWindow()
{
    struct winsize w;

	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == ERR)
		return Err::_10;
	g_gamesize.x = w.ws_col;
	g_gamesize.y = w.ws_row - UI_HEIGHT;
	m_winsize.x = w.ws_col;
	m_winsize.y = w.ws_row;
	return 0;
}

int 	SystemRender::draw(const Vector2f& posf, const ComponentRender* obj) const
{
	(void)obj;
	const Vector2i&	posi = posf;

	if (mvwprintw(m_window, posi.y, posi.x, obj->getRepr()) == ERR)
		return Err::_14;
	return 0;
}
