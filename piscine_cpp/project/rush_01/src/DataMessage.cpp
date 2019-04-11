#include "DataMessage.hpp"

/*
** Builtin functions
*/

DataMessage::DataMessage(Type type, void* addr, std::string title) :
    m_type(type),
    m_addr(addr),
    m_title(title)
{
}

DataMessage::~DataMessage()
{
}

DataMessage&    DataMessage::operator=(const DataMessage& src)
{
    m_type = src.m_type;
    m_addr = src.m_addr;
    return *this;
}


/*
** Class Specific functions
*/

std::string     	DataMessage::getTitle(void)
{
    return m_title;
}

DataMessage::Type	DataMessage::getType(void)
{
    return m_type;
}

void*       		DataMessage::getAddr(void)
{
    return m_addr;
}
