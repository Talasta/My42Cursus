#include "DisplayNcurse.hpp"
#include <ncurses.h>
#include <string>
#include <cstring>

/*
** Builtin functions
*/

DisplayNcurse::DisplayNcurse()
{
    initNcurse();
    screenSize();
}

DisplayNcurse::~DisplayNcurse()
{
    endwin();
}

/*
** Class Specific functions
*/

void    DisplayNcurse::initNcurse(void)
{
    initscr();
    start_color();
    raw();
    noecho();
    keypad(stdscr, true);
    nodelay(stdscr, TRUE);
    curs_set(0);

    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
}

void    DisplayNcurse::screenSize(void)
{
    struct winsize w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	m_winsize_x = w.ws_col;
	m_winsize_y = w.ws_row;
}

void    DisplayNcurse::render(std::deque<DataMessage*> lst)
{
    DataMessage*    data;
    int     x(0);
    int     y(0);

    // Check size of the screen
    clear();
    screenSize();

    for (std::deque<DataMessage*>::iterator it = lst.begin(); it != lst.end(); ++it)
    {
        data = *it;
        move(y, x);
        if (data->getType() == DataMessage::Title)
        {
            renderTitle(*data);
        }
        if (data->getType() == DataMessage::Single)
        {
            renderSingle(*data);
        }
        if (data->getType() == DataMessage::Serie)
        {
            renderSerie(*data);
        }
        y++;
    }
    refresh();
}

void    DisplayNcurse::renderTitle(DataMessage& msg)
{
    attron(COLOR_PAIR(5));
    printw("%s ", "-----");
    if (msg.getTitle().length() != 0)
    {
        printw("%s", msg.getTitle().c_str());
    }

    std::string     bar("");
    while (bar.length() < m_winsize_x - (7 + msg.getTitle().length()))
    {
        bar += "-";
    }
    printw(" %s", bar.c_str());
    attroff(COLOR_PAIR(5));
}

void    DisplayNcurse::renderSingle(DataMessage& msg)
{
    attron(COLOR_PAIR(6));
    if (msg.getTitle().length() != 0)
    {
        printw("%s : ", msg.getTitle().c_str());
    }
    attroff(COLOR_PAIR(6));
    std::string  data = *(reinterpret_cast<std::string*>(msg.getAddr()));
    printw("%s", data.c_str());
}

void    DisplayNcurse::renderSerie(DataMessage& msg)
{
    attron(COLOR_PAIR(6));
    if (msg.getTitle().length() != 0)
    {
        printw("%s : ", msg.getTitle().c_str());
    }
    attroff(COLOR_PAIR(6));
    printw("[");
    std::deque<float>  data = *(reinterpret_cast<std::deque<float>*>(msg.getAddr()));
    int len = m_winsize_x - (msg.getTitle().length() + 12);
    if (len > 10)
    {
        std::string     bar("");
        while (bar.length() < static_cast<unsigned long>(static_cast<float>(len) * data.back()))
        {
            bar += "|";
        }
        attron(COLOR_PAIR(4));
        printw("%s", bar.c_str());
        attroff(COLOR_PAIR(4));
        len -= bar.length();
        bar = "";
        while (bar.length() < static_cast<unsigned long>(len))
        {
            bar += "|";
        }
        attron(COLOR_PAIR(2));
        printw("%s", bar.c_str());
        attroff(COLOR_PAIR(2));
    }
    printw(" %5.2f%%]", data.back() * 100.f);
}
