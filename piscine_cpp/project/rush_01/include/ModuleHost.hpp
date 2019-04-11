#ifndef MODULEHOST_HPP
# define MODULEHOST_HPP

# include "IMonitorModules.hpp"
# include <iostream>

class ModuleHost : public IMonitorModule
{
public:

	ModuleHost();
	virtual ~ModuleHost();

	virtual void    send(std::deque<DataMessage*>*);
    virtual void    refresh(void);

private:

	std::string			m_host;
	std::string			m_user;

	ModuleHost(const ModuleHost&);
	ModuleHost & operator=(const ModuleHost&);

};

#endif
