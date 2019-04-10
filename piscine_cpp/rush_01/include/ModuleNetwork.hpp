#ifndef MODULENETWORK_HPP
# define MODULENETWORK_HPP

#include "IMonitorModules.hpp"

class ModuleNetwork : public IMonitorModule
{
public:

	ModuleNetwork();
	virtual ~ModuleNetwork();

	virtual void    send(std::deque<DataMessage*>*);
    virtual void    refresh(void);

private:
	ModuleNetwork(const ModuleNetwork&);
	ModuleNetwork & operator=(const ModuleNetwork&);

};

#endif
