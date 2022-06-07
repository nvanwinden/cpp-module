#include "../includes/Bureaucrat.hpp"

#define GREEN	"\033[0;32m"
#define RED		"\033[0;31m"
#define RESET	"\033[0m"

int main ( void ) {

	std::cout << std::endl << "---" << std::endl << std::endl;
	std::cout << GREEN << "• Instantiate a Bureaucrat using an invalid grade [too high] •" << RESET << std::endl << std::endl;

	try {
		Bureaucrat a = Bureaucrat("a", 0);
	}
	catch (std::exception & e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	std::cout << std::endl << "---" << std::endl << std::endl;
	std::cout << GREEN << "• Instantiate a Bureaucrat using an invalid grade [too low] •" << RESET << std::endl << std::endl;

	try {
		Bureaucrat b = Bureaucrat("b", 151);
	}
	catch (std::exception & e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	std::cout << std::endl << "---" << std::endl << std::endl;

	try {
		std::cout << GREEN << "• Instantiate a Bureaucrat using a valid grade •" << RESET << std::endl << std::endl;

		Bureaucrat c = Bureaucrat("c", 3);
	
		std::cout << GREEN << "• Increment grade until out of range •" << RESET << std::endl << std::endl;

		std::cout << c << std::endl;
		c.incrementGrade();
		std::cout << c << std::endl;
		c.incrementGrade();
		std::cout << c << std::endl;
		c.incrementGrade();
		std::cout << c << std::endl;
	}
	catch (std::exception & e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	std::cout << std::endl << "---" << std::endl << std::endl;

	try {
		std::cout << GREEN << "• Instantiate a Bureaucrat using a valid grade •" << RESET << std::endl << std::endl;

		Bureaucrat d = Bureaucrat("d", 148);

		std::cout << GREEN << "• Decrement grade until out of range •" << RESET << std::endl << std::endl;

		std::cout << d << std::endl;
		d.decrementGrade();
		std::cout << d << std::endl;
		d.decrementGrade();
		std::cout << d << std::endl;
		d.decrementGrade();
		std::cout << d << std::endl;
	}
	catch (std::exception & e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	std::cout << std::endl << "---" << std::endl << std::endl;

	return (0);
}
