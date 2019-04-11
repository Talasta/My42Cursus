#ifndef MODULECPU_HPP
# define MODULECPU_HPP

# include "IMonitorModules.hpp"
# include <deque>
# include <iostream>

class ModuleCPU : public IMonitorModule
{
public:

	ModuleCPU();
	virtual ~ModuleCPU();

	virtual void    send(std::deque<DataMessage*>*);
    virtual void    refresh(void);

private:
	std::deque<float>		m_load;
	std::string				m_nbCpu;
	std::string				m_clockPerSec;
	std::string				m_model;
	unsigned long long 		m_previousTotalTicks;
	unsigned long long 		m_previousIdleTicks;


	float 					GetCPULoad(void);
	float					CalculateCPULoad(unsigned long long, unsigned long long);

	ModuleCPU(const ModuleCPU&);
	ModuleCPU & operator=(const ModuleCPU&);

};

#define CPU_LOAD_MAXLEN 200

#endif
