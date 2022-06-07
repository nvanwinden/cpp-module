#include "../includes/Span.hpp"

#include <iostream>
#include <numeric>

/* constructors and destructor */

Span::Span( void ) : _max(0), _stored(0) {}

Span::Span( unsigned int n) : _max(n), _stored(0) {}

Span::Span( Span const & src ) : _span(src._span),
	_max(src._max), _stored(src._stored) { *this = src; }

Span::~Span( void ) {};

/* copy assignment operator */

Span & Span::operator=( Span const & rhs ) {

	(void)rhs;
	return (*this);
}

/* Public member functions */

int	randomNumber () { return ( rand() % 90000 ); }

void	Span::addNumbers( void ) {

	if (this->_stored == this->_max)
		throw(SpanFullException());

	this->_span.resize(this->_max);
	std::generate(this->_span.begin(), this->_span.end(), randomNumber);
	this->_stored += this->_max;
	return ;
}

void	Span::addNumber( int n ) {

	if (this->_stored == this->_max)
		throw(SpanFullException());
	this->_span.push_back(n);
	_stored++;
	return ;
}

void	Span::printSpan( void ) {

	for(size_t i  =0; i < this->_span.size(); i++)
		std::cout << this->_span.at(i) << ' ';
	std::cout << std::endl;
}

int		Span::shortestSpan( void ) {

	if (this->_stored <= 1)
		throw(NotEnoughNumbersStoredException());
	sort(this->_span.begin(), this->_span.end());
	int result[this->_span.size()];
	std::adjacent_difference(this->_span.begin(), this->_span.end(), result);
	int n = sizeof(result) / sizeof(result[0]);
	std::vector<int> diff;
	diff.insert(diff.begin(), result, result + n);
	diff.erase(diff.begin());
	sort(diff.begin(), diff.end());
	return (*diff.begin());
};

int		Span::longestSpan( void ) {

	if (this->_stored <= 1)
		throw(NotEnoughNumbersStoredException());
	sort(this->_span.begin(), this->_span.end());
	std::vector<int>::iterator begin = this->_span.begin();
	std::vector<int>::iterator end = this->_span.end();
	end--;
	return(*end - *begin);
}

/* exceptions */

const char *	Span::SpanFullException::what() const throw() {

	return ("Span::SpanFullException");
}

const char *	Span::NotEnoughNumbersStoredException::what() const throw() {

	return ("Span::NotEnoughNumbersStoredException");
}
