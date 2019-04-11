#ifndef CORE_HPP
# define CORE_HPP

# include "IMonitorModules.hpp"
# include "IMonitorDisplay.hpp"
# include "DataMessage.hpp"
# include <deque>

class Core
{
public:
	enum Display
	{
		NcurseDisp,
		UiDisp,
		COUNT
	};
	Core(void);
	Core(Display disp);
	~Core();

	void		addModule(IMonitorModule* module);
	void		refresh(void);
	void		init(void);
	void		render(void);
    void		clear(void);
	void		setDisplay(Display disp = NcurseDisp);

	typedef std::deque<IMonitorModule*>::iterator iterator;

private:

	std::deque<IMonitorModule*>	m_modules;
	std::deque<DataMessage*>	m_data;
	IMonitorDisplay*			m_display;

	Core(const Core&);
	Core & operator=(const Core&);

};

#endif
