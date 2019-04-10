#ifndef MODULEOS_HPP
# define MODULEOS_HPP

# include "IMonitorModules.hpp"
# include <iostream>

class ModuleOS : public IMonitorModule
{
public:

	ModuleOS();
	virtual ~ModuleOS();

	virtual void    send(std::deque<DataMessage*>*);
    virtual void    refresh(void);

private:

	std::string			m_sysname;
	std::string			m_nodename;
	std::string			m_release;
	std::string			m_version;
	std::string			m_machine;

	ModuleOS(const ModuleOS&);
	ModuleOS & operator=(const ModuleOS&);

};

#endif
