#include "ModuleRAM.hpp"
#include <mach/vm_statistics.h>
#include <mach/mach_types.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>
#include <sstream>
#include <iostream>

/*
** Builtin functions
*/

ModuleRAM::ModuleRAM() :
    m_serieUsed(std::deque<float>(.0f)),
    m_otherUsed(std::deque<float>(.0f))
{
}

ModuleRAM::~ModuleRAM()
{
}

/*
** Class Specific functions
*/

void    ModuleRAM::send(std::deque<DataMessage*>* data)
{
    data->push_back(new DataMessage(DataMessage::Title, 0, "Memory Info"));
    data->push_back(new DataMessage(DataMessage::Single, reinterpret_cast<void*>(&m_free), "Mem Free"));
    data->push_back(new DataMessage(DataMessage::Single, reinterpret_cast<void*>(&m_used), "Mem Used"));
    data->push_back(new DataMessage(DataMessage::Serie, reinterpret_cast<void*>(&m_otherUsed), "Real-used"));
    data->push_back(new DataMessage(DataMessage::Serie, reinterpret_cast<void*>(&m_serieUsed), "Mem-Cache"));
}

void    ModuleRAM::refresh(void)
{
    getMemInfos();
    while (m_serieUsed.size() > RAM_LOAD_MAXLEN)
    {
        m_serieUsed.pop_front();
    }
    m_otherUsed.push_back(GetSystemMemoryUsagePercentage());
    while (m_otherUsed.size() > RAM_LOAD_MAXLEN)
    {
        m_otherUsed.pop_front();
    }
}

void    ModuleRAM::getMemInfos(void)
{
    vm_size_t page_size;
    mach_port_t mach_port;
    mach_msg_type_number_t count;
    vm_statistics64_data_t vm_stats;
    long long infos[2];
    std::ostringstream mem_infos;

    mach_port = mach_host_self();
    count = sizeof(vm_stats) / sizeof(natural_t);
    if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
       KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,
                                        (host_info64_t)&vm_stats, &count))
    {
       infos[0] = (int64_t)vm_stats.free_count * (int64_t)page_size;

       infos[1] = ((int64_t)vm_stats.active_count +
                                (int64_t)vm_stats.inactive_count +
                                (int64_t)vm_stats.wire_count) *  (int64_t)page_size;
    }

    std::ostringstream ss1;
    ss1 << infos[0]/1e+6;
    m_free = ss1.str();
    m_free += "M";
    std::ostringstream ss2;
    ss2 << infos[1]/1e+6;
    m_used = ss2.str();
    m_used += "M";
    m_serieUsed.push_back(infos[1]/1e+6 / (infos[0]/1e+6 + infos[1]/1e+6));
}


double  ModuleRAM::ParseMemValue(const char * b)
{
   while((*b)&&(isdigit(*b) == false)) b++;
   return isdigit(*b) ? atof(b) : -1.0;
}

float   ModuleRAM::GetSystemMemoryUsagePercentage(void)
{
   FILE * fpIn = popen("/usr/bin/vm_stat", "r");
   if (fpIn)
   {
      double pagesUsed = 0.0, totalPages = 0.0;
      char buf[512];
      while(fgets(buf, sizeof(buf), fpIn) != NULL)
      {
         if (strncmp(buf, "Pages", 5) == 0)
         {
            double val = ParseMemValue(buf);
            if (val >= 0.0)
            {
               if ((strncmp(buf, "Pages wired", 11) == 0)||(strncmp(buf, "Pages active", 12) == 0)) pagesUsed += val;
               totalPages += val;
            }
         }
         else if (strncmp(buf, "Mach Virtual Memory Statistics", 30) != 0) break;  // Stop at "Translation Faults", we don't care about anything at or below that
      }
      pclose(fpIn);

      if (totalPages > 0.0) return (float) (pagesUsed/totalPages);
   }
   return -1.0f;  // indicate failure
}
