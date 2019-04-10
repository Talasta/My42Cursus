#ifndef DISPLAYNCURSE_HPP
# define DISPLAYNCURSE_HPP

# include "IMonitorDisplay.hpp"
# include <ncurses.h>
# include <string>
# include <cstring>
# include <unistd.h>
# include <sys/ioctl.h>

class DisplayNcurse : public IMonitorDisplay
{

public:

	DisplayNcurse();
	virtual ~DisplayNcurse();

	virtual void    render(std::deque<DataMessage*>);

private:

	unsigned long	m_winsize_x;
	unsigned long	m_winsize_y;

	virtual void    renderSingle(DataMessage& msg);
	virtual void    renderSerie(DataMessage& msg);
	void 			renderTitle(DataMessage& msg);

	void			initNcurse(void);
	void			screenSize(void);

	DisplayNcurse(const DisplayNcurse&);
	DisplayNcurse & operator=(const DisplayNcurse&);

};

#endif
