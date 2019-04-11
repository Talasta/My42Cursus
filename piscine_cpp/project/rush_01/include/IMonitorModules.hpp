#ifndef I_MONITOR_MODULE_HPP
# define I_MONITOR_MODULE_HPP

# include <deque>
# include "DataMessage.hpp"

class IMonitorModule
{

public:

    IMonitorModule();
    virtual ~IMonitorModule();

    virtual void    send(std::deque<DataMessage*>* data) = 0;
    virtual void    refresh(void) = 0;

};
#endif
