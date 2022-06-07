#ifndef EASYFIND_H
# define EASYFIND_H

#include <algorithm>
#include <exception>

template < typename T >
typename T::const_iterator	easyfind(T const & container, int n)
{
	typename T::const_iterator it;

	it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw std::exception();
	return (it);
}

#endif
