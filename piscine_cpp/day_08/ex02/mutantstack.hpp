#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iterator>
# include <stack>
# include <deque>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:

	MutantStack() : std::stack<T, Container>() {};
	MutantStack(const Container& src) : std::stack<T, Container>(src) {};
	~MutantStack() {};

	typename Container::iterator	begin(void) { return this->c.begin(); };
	typename Container::iterator	end(void) { return this->c.end(); };
	typedef typename Container::iterator iterator;

};

#endif
