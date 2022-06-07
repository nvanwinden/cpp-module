#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

/* constructors and destructor */

Intern::Intern( void ) {

	return ;
}

Intern::Intern( Intern const & src ) {

	*this = src;
	return ;
}

Intern::~Intern( void ) {

	return ;
}

/* copy assignment operator */

Intern & Intern::operator=( Intern const & rhs ) {

	(void)rhs;
	return (*this);
}

/* public member functions */

AForm * Intern::makeForm( std::string form, std::string target ) {

	AForm		*newForm;
	std::string	type[3] = {
		"shrubbery request",
		"robotomy request",
		"presidential request"
	};
	newForm = NULL;
	for (int i = 0; i < 3; i++) {
		if (type[i] == form) {
			switch(i) {
				case SHRUBBERY:
					newForm = new ShrubberyCreationForm(target);
					break;
				case ROBOTOMY:
					newForm = new RobotomyRequestForm(target);
					break;
				case PRESIDENTIAL:
					newForm = new PresidentialPardonForm(target);
					break;
			}
		}
	}
	if (newForm == NULL)
		throw(FormDoesNotExistException());
	std::cout << "Intern creates " << newForm->getName() << std::endl;
	return (newForm);
}

/* exceptions */

const char *	Intern::FormDoesNotExistException::what() const throw() {

	return ("Intern::FormDoesNotExistException");
}
