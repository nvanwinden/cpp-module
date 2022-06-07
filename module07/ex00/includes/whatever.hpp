#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template < typename T >
void		swap( T & a, T & b ) {

	T tmp = a;
	a = b;
	b = tmp;
	return ;
}

template < typename T >
T const &	min( T const & a, T const & b ) {

	if (b <= a)
		return (b);
	return (a);
}

template < typename T >
T const &	max( T const & a, T const & b) {

	if (b >= a)
		return (b);
	return (a);
}

#endif
