#include "ModuleOS.hpp"
#include <sys/utsname.h>

/*
** Builtin functions
*/

ModuleOS::ModuleOS()
{
    struct utsname unameData;
    uname(&unameData);
    m_sysname = unameData.sysname;
    m_nodename = unameData.nodename;
    m_release = unameData.release;
    m_version = unameData.version;
    m_machine = unameData.machine;
}

ModuleOS::~ModuleOS()
{
}

/*
** Class Specific functions
*/

void    ModuleOS::send(std::deque<DataMessage*>* data)
{
    data->push_back(new DataMessage(DataMessage::Title, 0, "OS & System"));
    data->push_back(new DataMessage(DataMessage::Single, reinterpret_cast<void*>(&m_sysname), "Sysname"));
    data->push_back(new DataMessage(DataMessage::Single, reinterpret_cast<void*>(&m_release), "Release"));
    data->push_back(new DataMessage(DataMessage::Single, reinterpret_cast<void*>(&m_machine), "Machine"));
}

void    ModuleOS::refresh(void)
{
}
