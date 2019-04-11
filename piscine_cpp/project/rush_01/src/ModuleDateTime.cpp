#include "ModuleDateTime.hpp"

/*
** Builtin functions
*/

ModuleDateTime::ModuleDateTime() : m_timestamp(time(NULL))
{
}

ModuleDateTime::~ModuleDateTime()
{
}

/*
** Class Specific functions
*/

void    ModuleDateTime::send(std::deque<DataMessage*>* data)
{
    data->push_back(new DataMessage(DataMessage::Title, 0, "Date & Time"));
    data->push_back(new DataMessage(DataMessage::Single, reinterpret_cast<void*>(&m_date), "DATE"));
    data->push_back(new DataMessage(DataMessage::Single, reinterpret_cast<void*>(&m_num), "TIME"));
}

void    ModuleDateTime::refresh(void)
{
    char        buffer[80];
    struct tm*  timeinfo;

    time(&m_timestamp);
    timeinfo = localtime(&m_timestamp);
    strftime(buffer,80,"%d %b %Y",timeinfo);
    m_date = buffer;
    strftime(buffer,80,"%H:%M:%S",timeinfo);
    m_num = buffer;
}
