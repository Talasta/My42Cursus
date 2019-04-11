#ifndef DATAMESSAGE_HPP
# define DATAMESSAGE_HPP

# include <iostream>

class DataMessage
{
public:

    enum Type
    {
        Serie = 0,
        Single,
        Title,
        COUNT_DATA
    };

	DataMessage(Type type, void* addr, std::string title = "");
	~DataMessage();
    DataMessage & operator=(const DataMessage&);

	Type 		getType(void);
	void*		getAddr(void);
    std::string getTitle(void);

private:

	Type 		    m_type;
	void*		    m_addr;
    std::string     m_title;

	DataMessage();
	DataMessage(const DataMessage&);

};

#endif
