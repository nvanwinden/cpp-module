#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main ( void ) {

	srand(time(0)); // RobotomyRequestForm

	std::cout << std::endl << "---" << std::endl << std::endl;
	std::cout << GREEN << "• Test bureaucrat with valid grade to sign and execute ShrubberyCreationForm •" << RESET << std::endl << std::endl;
	try {
		Bureaucrat random = Bureaucrat("random", 50);
		ShrubberyCreationForm a = ShrubberyCreationForm("home");
		random.signForm(a);
		random.executeForm(a);
	}
	catch (std::exception & e) {
		std::cout << RED << e.what() << RESET <<std::endl;
	}
	catch (std::string e) {
		std::cout << RED << e << RESET <<std::endl;
	}

	std::cout << std::endl << "---" << std::endl << std::endl;
	std::cout << GREEN << "• Test bureaucrat with valid grade trying to execute a form that isn't signed •" << RESET << std::endl << std::endl;
	try {
		Bureaucrat random = Bureaucrat("random", 40);
		RobotomyRequestForm a = RobotomyRequestForm("28c");
		random.executeForm(a);
		std::cout << std::endl << GREEN << "• Bureaucrat signs the form and executes •" << RESET << std::endl << std::endl;
		random.signForm(a);
		random.executeForm(a);
	}
	catch (std::exception & e) {
		std::cout << RED << e.what() << RESET <<std::endl;
	}
	catch (std::string e) {
		std::cout << RED << e << RESET <<std::endl;
	}

	std::cout << std::endl << "---" << std::endl << std::endl;
	std::cout << GREEN << "• Test bureaucrat with invalid grade to execute form •" << RESET << std::endl << std::endl;
	try {
		Bureaucrat random = Bureaucrat("random", 20);
		PresidentialPardonForm a = PresidentialPardonForm("5d");
		random.signForm(a);
		random.executeForm(a);
		std::cout << std::endl << GREEN << "• Increment grade until valid •" << RESET << std::endl << std::endl;
		while (random.getGrade() != a.getExec())
		{
			random.incrementGrade();
			std::cout << random << std::endl;
		}
		std::cout << GREEN << "• Bureaucrat tries to execute form again •" << RESET << std::endl << std::endl;
		random.executeForm(a);
	}
	catch (std::exception & e) {
		std::cout << RED << e.what() << RESET <<std::endl;
	}
	catch (std::string e) {
		std::cout << RED << e << RESET <<std::endl;
	}
	std::cout << std::endl << "---" << std::endl << std::endl;

	return (0);
}
