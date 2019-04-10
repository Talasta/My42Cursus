#include "Core.hpp"

#include "ModuleHost.hpp"
#include "ModuleOS.hpp"
#include "ModuleDateTime.hpp"
#include "ModuleCPU.hpp"
#include "ModuleRAM.hpp"
#include "DisplayNcurse.hpp"
#include "DisplaySfml.hpp"

/*
** Builtin functions
*/

Core::Core(void) :
    m_modules(std::deque<IMonitorModule*>()),
    m_data(std::deque<DataMessage*>())
{

}

Core::Core(Display disp) :
    m_modules(std::deque<IMonitorModule*>()),
    m_data(std::deque<DataMessage*>())
{
    if (disp == Core::UiDisp)
    {
        // # TODO: change here for the other module
        m_display = dynamic_cast<IMonitorDisplay*>( new DisplaySfml(m_data) );
    }
    else
    {
        m_display = dynamic_cast<IMonitorDisplay*>( new DisplayNcurse() );
    }
}

Core::~Core()
{
    DisplayNcurse*      display;
    DisplaySfml*        displaySfml;
    if ((display = dynamic_cast<DisplayNcurse*>(m_display)))
    {
        delete display;
    }
    if ((displaySfml = dynamic_cast<DisplaySfml*>(m_display)))
    {
        delete displaySfml;
    }

    ModuleHost*     mod1;
    ModuleOS*       mod2;
    ModuleDateTime* mod3;
    ModuleCPU*      mod4;
    ModuleRAM*      mod5;

    while (m_modules.size() > 0)
    {
        if ((mod1 = dynamic_cast<ModuleHost*>(m_modules.back())))
        {
            delete mod1;
        }
        else if ((mod2 = dynamic_cast<ModuleOS*>(m_modules.back())))
        {
            delete mod2;
        }
        else if ((mod3 = dynamic_cast<ModuleDateTime*>(m_modules.back())))
        {
            delete mod3;
        }
        else if ((mod4 = dynamic_cast<ModuleCPU*>(m_modules.back())))
        {
            delete mod4;
        }
        else if ((mod5 = dynamic_cast<ModuleRAM*>(m_modules.back())))
        {
            delete mod5;
        }
        m_modules.pop_back();
	}
}

void    Core::setDisplay(Display disp) {
    if (disp == Core::UiDisp)
    {
        // # TODO: change here for the other module
        m_display = dynamic_cast<IMonitorDisplay*>( new DisplaySfml(m_data) );
    }
    else
    {
        m_display = dynamic_cast<IMonitorDisplay*>( new DisplayNcurse() );
    }
}

/*
** Class Specific functions
*/

void    Core::addModule(IMonitorModule* module)
{
    if (module)
    {
        m_modules.push_back(module);
    }
}

template<typename T>
void    tryRefresh(Core::iterator it)
{
    T*      module;

    if ((module = dynamic_cast<T*>(*it)))
    {
        module->refresh();
    }
}

template<typename T>
void    trySend(Core::iterator it, std::deque<DataMessage*>* data)
{
    T*      module;

    if ((module = dynamic_cast<T*>(*it)))
    {
        module->send(data);
    }
}

void    Core::render(void)
{
    DisplayNcurse*      display;
    DisplaySfml*        displaySfml;
    if ((display = dynamic_cast<DisplayNcurse*>(m_display)))
    {
        display->render(m_data);
    }
    // # TODO: change here for the other module
    if ((displaySfml = dynamic_cast<DisplaySfml*>(m_display)))
    {
        displaySfml->render(m_data);
    }
}

void    Core::clear(void)
{
    while (m_data.size())
    {
        delete m_data.back();
        m_data.pop_back();
    }
}

void    Core::refresh(void)
{
    for (Core::iterator  it = m_modules.begin(); it != m_modules.end(); ++it)
    {
        tryRefresh<ModuleHost>(it);
        tryRefresh<ModuleOS>(it);
        tryRefresh<ModuleDateTime>(it);
        tryRefresh<ModuleCPU>(it);
        tryRefresh<ModuleRAM>(it);
    }
}

void    Core::init(void)
{
    clear();
    for (Core::iterator  it = m_modules.begin(); it != m_modules.end(); ++it)
    {
        trySend<ModuleHost>(it, &m_data);
        trySend<ModuleOS>(it, &m_data);
        trySend<ModuleDateTime>(it, &m_data);
        trySend<ModuleRAM>(it, &m_data);
        trySend<ModuleCPU>(it, &m_data);
    }
}
