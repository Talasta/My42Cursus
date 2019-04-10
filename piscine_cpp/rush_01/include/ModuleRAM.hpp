#ifndef MODULERAM_HPP
# define MODULERAM_HPP

# include "IMonitorModules.hpp"
# include <deque>

class ModuleRAM : public IMonitorModule
{
public:

	ModuleRAM();
	virtual ~ModuleRAM();

	virtual void	send(std::deque<DataMessage*>*);
    virtual void    refresh(void);

private:
	std::string		 		m_free;
	std::string		 		m_used;
	std::deque<float> 		m_serieUsed;
	std::deque<float> 		m_otherUsed;

	void    	getMemInfos(void);
	float   	GetSystemMemoryUsagePercentage(void);
	double  	ParseMemValue(const char * b);

	ModuleRAM(const ModuleRAM&);
	ModuleRAM & operator=(const ModuleRAM&);

};

#define RAM_LOAD_MAXLEN 200

#endif
