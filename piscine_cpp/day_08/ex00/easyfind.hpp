#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>
# include <iterator>

template<typename T>
int 	easyfind(T var1, int var2)
{
	typename T::iterator it = std::find(var1.begin(), var1.end(), var2);
	if (it != var1.end())
	{
		return var2;
	}
	else
	{
		 throw std::invalid_argument( "value not found in container" );
	}
};

#endif
