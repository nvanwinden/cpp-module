#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template < typename T >
void	printElement( T const & element ) {

	std::cout << element << std::endl;
}

template < typename T >
void	iter( T const array[], size_t const & len, void(*f)(T const &) ) {

	if (array == NULL)
		return ;
	for (size_t i = 0; i < len; i++) {
		f(array[i]);
	}
}

#endif
