#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class Span {

public:

	Span( unsigned int n );
	Span( Span const & src );
	~Span( void );

	Span &	operator=( Span const & rhs );

	void	addNumber( int n );
	void	addNumbers( void );
	int		shortestSpan( void );
	int		longestSpan( void );
	void	printSpan( void );

	class SpanFullException : public std::exception {

	public:

		const char*	what() const throw();
	};

	class NotEnoughNumbersStoredException : public std::exception {

	public:

		const char*	what() const throw();
	};

private:

	Span( void );
	std::vector<int>	_span;
	unsigned int const	_max;
	unsigned int		_stored;

};

#endif
