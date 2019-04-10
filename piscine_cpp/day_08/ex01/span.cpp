#include "span.hpp"

/*
** Builtin functions
*/

Span::Span(unsigned int n) : m_n(n)
{
    m_set = std::set<int>();
}

Span::~Span()
{
}

Span::Span(const Span& src)
{
    *this = src;
}

Span&   Span::operator=(const Span& src)
{
    // delete [] m_data;
    // m_data = src.m_data;
    // m_nb = src.m_nb;
    m_n = src.m_n;
    m_set = src.m_set;
    return *this;
}

/*
** Class Specific functions
*/

void 	Span::addNumber(int n)
{
    if (m_set.size() == m_n)
    {
        throw Span::SpanFilledException();
    }
    m_set.insert(n);
}

int		Span::shortestSpan(void)
{
    if (m_set.size() < 2)
    {
        throw Span::NoSpanException();
    }
    int     min = INT_MAX;
    std::set<int>::iterator it;
    std::set<int>::iterator it_1 = ++m_set.begin();
    for(it = m_set.begin(); it_1 != m_set.end(); ++it)
    {
        if (std::abs(*it - *it_1) < min)
        {
            min = std::abs(*it - *it_1);
        }
        ++it_1;
    }
    return min;
}

int		Span::longestSpan(void)
{
    if (m_set.size() < 2)
    {
        throw Span::NoSpanException();
    }
    int     max = INT_MIN;
    std::set<int>::iterator it;
    std::set<int>::iterator it_1 = ++m_set.begin();
    for(it = m_set.begin(); it_1 != m_set.end(); ++it)
    {
        if (std::abs(*it - *it_1) > max)
        {
            max = std::abs(*it - *it_1);
        }
        ++it_1;
    }
    return max;
}

/* *****************************************************************************
** SpanFilledException Class
*/

const char* Span::SpanFilledException::what() const throw()
{
	return ("span is fully filled.");
}

Span::SpanFilledException::~SpanFilledException(void) throw ()
{
}

Span::SpanFilledException::SpanFilledException(void)
{
}

Span::SpanFilledException::SpanFilledException(const Span::SpanFilledException&)
{
}

/* *****************************************************************************
** NoSpanException Class
*/

const char* Span::NoSpanException::what() const throw()
{
	return ("span to small to call shortestSpan() or longestSpan().");
}

Span::NoSpanException::~NoSpanException(void) throw ()
{
}

Span::NoSpanException::NoSpanException(void)
{
}

Span::NoSpanException::NoSpanException(const Span::NoSpanException&)
{
}
