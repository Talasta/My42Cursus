#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <set>

class Span
{
public:

	Span(unsigned int n);
	~Span();
	Span(const Span&);
	Span & operator=(const Span&);

	void 	addNumber(int n);
	int		shortestSpan(void);
	int		longestSpan(void);

	class SpanFilledException: public std::exception
	{
	public:
		virtual const char* what() const throw();

		SpanFilledException(void);
		virtual ~SpanFilledException(void) throw ();
		SpanFilledException(const SpanFilledException&);

	private:
		SpanFilledException& 	operator=(const SpanFilledException&);
	};

	class NoSpanException: public std::exception
	{
	public:
		virtual const char* what() const throw();

		NoSpanException(void);
		virtual ~NoSpanException(void) throw ();
		NoSpanException(const NoSpanException&);

	private:
		NoSpanException& 	operator=(const NoSpanException&);
	};

private:
	unsigned int		m_n;
	std::set<int>		m_set;

	Span();

};

#endif
