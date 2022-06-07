#include "../includes/Span.hpp"

#define GREEN	"\033[0;32m"
#define RED		"\033[0;31m"
#define RESET	"\033[0m"

#include <iostream>

int	testSubject( void ) {

	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return 0;
}

int main ( void ) {

	std::srand(time(0));

	std::cout << GREEN << "• Test provided by subject •" << RESET << std::endl << std::endl;

	testSubject();

	std::cout << std::endl;
	std::cout << GREEN << "• Try to add element to a full span •" << RESET << std::endl << std::endl;

	try {
		int	spanSize = 20;
		Span fullSpan(spanSize);
		fullSpan.addNumbers();
		fullSpan.addNumber(5);
	}
	catch (std::exception & e) {
		std::cout << RED << e.what() << RESET <<std::endl;
	}

	std::cout << std::endl;
	std::cout << GREEN << "• Test big span •" << RESET << std::endl << std::endl;

	try {
		int	spanSize = 100;
		Span bigSpan(spanSize);
		bigSpan.addNumbers();
		std::cout << bigSpan.shortestSpan() << std::endl;
		std::cout << bigSpan.longestSpan() << std::endl;
	}
	catch (std::exception & e) {
		std::cout << RED << e.what() << RESET <<std::endl;
	}

	std::cout << std::endl;
	std::cout << GREEN << "• Test bigger span •" << RESET << std::endl << std::endl;

	try {
		int	spanSize = 20001;
		Span biggerSpan(spanSize);
		biggerSpan.addNumbers();
		std::cout << biggerSpan.shortestSpan() << std::endl;
		std::cout << biggerSpan.longestSpan() << std::endl;
	}
	catch (std::exception & e) {
		std::cout << RED << e.what() << RESET <<std::endl;
	}

	std::cout << std::endl;
	std::cout << GREEN << "• Test not enough numbers •" << RESET << std::endl << std::endl;

	try {
		int	spanSize = 5;
		Span singleNum(spanSize);
		singleNum.addNumber(42);
		std::cout << singleNum.shortestSpan() << std::endl;
		std::cout << singleNum.longestSpan() << std::endl;
	}
	catch (std::exception & e) {
		std::cout << RED << e.what() << RESET <<std::endl;
	}
}
