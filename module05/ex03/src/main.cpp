#include "../includes/Intern.hpp"

int main ( void ) {

	srand(time(0)); // RobotomyRequestForm

	std::cout << std::endl << "---" << std::endl << std::endl;
	std::cout << GREEN << "• Create an intern and make it create a form •" << RESET << std::endl << std::endl;

	Intern someRandomIntern;

	try {
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");

		std::cout << std::endl << GREEN << " • Make bureacrat sign form •" << RESET << std::endl << std::endl;

		Bureaucrat nilo("nilo", 20);
		nilo.signForm(*rrf);
		delete rrf;
	}
	catch (std::exception & e) {

		std::cout << RED << e.what() << RESET <<std::endl;
	}

	std::cout << std::endl << "---" << std::endl << std::endl;
	std::cout << GREEN << "• Create an intern and make it create a form that doesn't exist •" << RESET << std::endl << std::endl;
	try {
		AForm* doesntExist;
		doesntExist = someRandomIntern.makeForm("default", "default");
		delete doesntExist;
	}
	catch (std::exception & e) {

		std::cout << RED << e.what() << RESET <<std::endl;
	}
	std::cout << std::endl << "---" << std::endl << std::endl;

	return (0);
}
