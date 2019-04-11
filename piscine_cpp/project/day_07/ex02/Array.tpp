#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
public:

	Array() : m_data(NULL), m_n(0)
	{
	};

	Array(unsigned int n) : m_n(n)
	{
		m_data = new T[m_n];
		for (unsigned int i = 0; i < m_n; ++i)
		{
			m_data[i] = T();
		}
	};

	~Array()
	{
		if (m_data)
		{
			delete [] m_data;
		}
	};

	Array(const Array& src)
	{
		m_n = src.m_n;
		if (m_n != 0)
		{
			m_data = new T[m_n];
			for (unsigned int i = 0; i < m_n; ++i)
			{
				m_data[i] = src.m_data[i];
			}
		}
		else
		{
			m_data = NULL;
		}
	};

	Array & operator=(const Array& src)
	{
		if (m_n != 0)
		{
			delete [] m_data;
		}
		m_n = src.m_n;
		if (m_n != 0)
		{
			m_data = new T[m_n];
			for (unsigned int i = 0; i < m_n; ++i)
			{
				m_data[i] = src.m_data[i];
			}
		}
		else
		{
			m_data = NULL;
		}
		return *this;
	};

	T&	operator[](const int index) const
	{
		if (index < 0 || index >= static_cast<int>(m_n) || m_n == 0)
		{
			throw IndexRangeException();
		}
		return m_data[index];
	};

	unsigned int size()
	{
		return m_n;
	}

	class IndexRangeException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("Array index out of range");
		};

		IndexRangeException(void) {};
		virtual ~IndexRangeException(void) throw () {};
		IndexRangeException(const IndexRangeException&) {};

	private:
		IndexRangeException& 	operator=(const IndexRangeException&) {};
	};

private:
	T*				m_data;
	unsigned int	m_n;

};

#endif
