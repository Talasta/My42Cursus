#include "ModuleHost.hpp"

#include <unistd.h>

/*
** Builtin functions
*/

ModuleHost::ModuleHost()
{
    char hostname[1024];
    hostname[1023] = '\0';
    gethostname(hostname, 1023);
    m_host = hostname;
    getlogin_r(hostname, 1024);
    m_user = hostname;
}

ModuleHost::~ModuleHost()
{
}

/*
** Class Specific functions
*/

void    ModuleHost::send(std::deque<DataMessage*>* data)
{
    data->push_back(new DataMessage(DataMessage::Title, 0, "User Info"));
    data->push_back(new DataMessage(DataMessage::Single, reinterpret_cast<void*>(&m_host), "Hostname"));
    data->push_back(new DataMessage(DataMessage::Single, reinterpret_cast<void*>(&m_user), "Username"));
}

void    ModuleHost::refresh(void)
{
}
