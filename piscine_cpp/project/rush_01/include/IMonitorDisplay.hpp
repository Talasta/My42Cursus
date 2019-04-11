#ifndef I_MONITOR_DISPLAY_HPP
# define I_MONITOR_DISPLAY_HPP

# include "DataMessage.hpp"
# include <deque>

class IMonitorDisplay
{
    
public:

    IMonitorDisplay();
    virtual ~IMonitorDisplay();

    virtual void    render(std::deque<DataMessage*>) = 0;

protected:
    virtual void    renderSingle(DataMessage& msg) = 0;
    virtual void    renderSerie(DataMessage& msg) = 0;
};
#endif
