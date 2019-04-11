#include "ModuleCPU.hpp"

#include <sstream>
#include <unistd.h>
#include <mach/mach_init.h>
#include <mach/mach_error.h>
#include <mach/mach_host.h>
#include <mach/vm_map.h>
#include <sys/types.h>
#include <sys/sysctl.h>

/*
** Builtin functions
*/

ModuleCPU::ModuleCPU() :
    m_load(std::deque<float>(.0f)),
    m_previousTotalTicks(0),
    m_previousIdleTicks(0)
{
    char name[100];
    size_t size = sizeof(name);
    if (sysctlbyname("machdep.cpu.brand_string", &name, &size, NULL, 0) < 0)
    {
        m_clockPerSec = "Unknown";
        m_model = "Unknown";
    }
    else
    {
        std::string     s(name);
        m_model = s.substr(0, s.find(" @ "));
        m_clockPerSec = s.substr(s.find(" @ ") + 3, s.length());
    }
    std::ostringstream ss;
    ss << sysconf(_SC_NPROCESSORS_ONLN);
    m_nbCpu =  ss.str();
}

ModuleCPU::~ModuleCPU()
{
}

/*
** Class Specific functions
*/

void    ModuleCPU::send(std::deque<DataMessage*>* data)
{
    data->push_back(new DataMessage(DataMessage::Title, 0, "CPU Info"));
    data->push_back(new DataMessage(DataMessage::Single, reinterpret_cast<void*>(&m_model), "Model"));
    data->push_back(new DataMessage(DataMessage::Single, reinterpret_cast<void*>(&m_clockPerSec), "Rate"));
    data->push_back(new DataMessage(DataMessage::Single, reinterpret_cast<void*>(&m_nbCpu), "Cores"));
    data->push_back(new DataMessage(DataMessage::Serie, reinterpret_cast<void*>(&m_load), "CPU load"));
}

void    ModuleCPU::refresh(void)
{
    m_load.push_back(GetCPULoad());
    while (m_load.size() > CPU_LOAD_MAXLEN)
    {
        m_load.pop_front();
    }
}

float   ModuleCPU::CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
{

    unsigned long long totalTicksSinceLastTime = totalTicks - m_previousTotalTicks;
    unsigned long long idleTicksSinceLastTime  = idleTicks - m_previousIdleTicks;
    float ret = 1.0f - (
        (totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime / totalTicksSinceLastTime) : 0
    );
    m_previousTotalTicks = totalTicks;
    m_previousIdleTicks  = idleTicks;
    return ret;
}

float   ModuleCPU::GetCPULoad(void)
{
    host_cpu_load_info_data_t cpuinfo;
    mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;

    if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO,
            (host_info_t)&cpuinfo, &count) == KERN_SUCCESS)
    {
        unsigned long long totalTicks = 0;
        for(int i = 0; i < CPU_STATE_MAX; i++)
        {
            totalTicks += cpuinfo.cpu_ticks[i];
        }
        return CalculateCPULoad(cpuinfo.cpu_ticks[CPU_STATE_IDLE], totalTicks);
    }
    return -1.0f;
}
