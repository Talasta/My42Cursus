#ifndef MODULEDATETIME_HPP
# define MODULEDATETIME_HPP

#include "IMonitorModules.hpp"
#include <time.h>
#include <iostream>

class ModuleDateTime : public IMonitorModule
{
public:

	ModuleDateTime();
	virtual ~ModuleDateTime();

	virtual void    send(std::deque<DataMessage*>*);
    virtual void    refresh(void);

private:
	time_t				m_timestamp;
	std::string			m_date;
	std::string			m_num;


	ModuleDateTime(const ModuleDateTime&);
	ModuleDateTime & operator=(const ModuleDateTime&);

};

#endif
