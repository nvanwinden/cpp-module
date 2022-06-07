#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main ( void ) {

	std::cout << std::endl << "---" << std::endl << std::endl;
	std::cout << GREEN << "• Test form exceptions invalid grade [grade exec too high] •" << RESET << std::endl << std::endl;
	try {
		Form a = Form("a", 0, 5);
	}
	catch (std::exception & e) {
		std::cout << RED << e.what() << RESET <<std::endl;
	}

	std::cout << std::endl << "---" << std::endl << std::endl;
	std::cout << GREEN << "• Test form exceptions invalid grade [grade exec too low] •" << RESET << std::endl << std::endl;
	try {
		Form b = Form("b", 151, 5);
	}
	catch (std::exception & e) {
		std::cout << RED << e.what() << RESET <<std::endl;
	}

	std::cout << std::endl << "---" << std::endl << std::endl;
	std::cout << std::endl << GREEN << "• Test form exceptions invalid grade [grade sign too high] •" << RESET << std::endl << std::endl;
	try {
		Form c = Form("c", 5, 0);
	}
	catch (std::exception & e) {
		std::cout << RED << e.what() << RESET <<std::endl;
	}

	std::cout << std::endl << "---" << std::endl << std::endl;
	std::cout << GREEN << "• Test form exceptions invalid grade [grade sign too low] •" << RESET << std::endl << std::endl;
	try {
		Form d = Form("d", 5, 151);
	}
	catch (std::exception & e) {
		std::cout << RED << e.what() << RESET <<std::endl;
	}

	std::cout << std::endl << "---" << std::endl << std::endl;
	std::cout << GREEN << "• Valid form with invalid grade voor Bureaucrat to sign form [too low] •" << RESET << std::endl << std::endl;
	try {
		Form e = Form("e", 5, 20);
		Bureaucrat random = Bureaucrat("Random", 25);
		random.signForm(e);
	}
	catch (std::exception & e) {
		std::cout << RED << e.what() << RESET <<std::endl;
	}

	std::cout << std::endl << "---" << std::endl << std::endl;
	std::cout << GREEN << "• Valid form with valid grade for Bureaucrat •" << RESET << std::endl << std::endl;
	try {
		Form f = Form("f", 1, 20);
		Bureaucrat random = Bureaucrat("Random", 20);
		f.beSigned(random);
	}
	catch (std::exception & e) {
		std::cout << RED << e.what() << RESET <<std::endl;
	}

	std::cout << "---" << std::endl << std::endl;
	std::cout << GREEN << "• Test sign form •" << RESET << std::endl << std::endl;
	try {
		Form g = Form("g", 1, 20);
		Bureaucrat random = Bureaucrat("random", 19);
		random.signForm(g);
	}
	catch (std::exception & e) {
		std::cout << RED << e.what() << RESET <<std::endl;
	}
	std::cout << std::endl << "---" << std::endl << std::endl;
	return (0);
}
