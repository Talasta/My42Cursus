#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>

template<typename T, unsigned int LEN>
class	Array
{
public:

	Array()
	{
		m_a[0] = 0;
	}
	~Array() {}

	operator T*()
	{
		return reinterpret_cast<T*>(m_a);
	}

	operator T const*() const
	{
		return reinterpret_cast<T const*>(m_a);
	}

	void	push_back(const T& v)
	{
		T*	i = m_a;

		while (*i)
			++i;

		*i = v;
		i[1] = 0;
	}

	void	insert(unsigned int pos, const T& v)
	{
		unsigned int		i = len() + 1;

		while (i != pos)
		{
			m_a[i] = m_a[i - 1];
			--i;
		}
		m_a[i] = v;
	}

	void	erase(unsigned int pos)
	{
		T*	i = m_a + pos;

		while (*i)
		{
			*i = i[1];
			++i;
		}
	}

	unsigned int	find(const T& v) const
	{
		const T*	i = m_a;

		while (*i != v && *i)
			++i;

		return static_cast<unsigned int>(i - m_a);
	}

	unsigned int	len() const
	{
		const T*	i = m_a;

		while (*i)
			++i;

		return static_cast<unsigned int>(i - m_a);
	}

	Array& operator=(const Array& a)
	{
		unsigned int	i;

		for (i = 0; a[i]; ++i)
			m_a[i] = a[i];

		m_a[i] = 0;
		return *this;
	}

private:

	Array(const Array&);

	T	m_a[LEN];
};

#endif
