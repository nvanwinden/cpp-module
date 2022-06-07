#include "../includes/RobotomyRequestForm.hpp"

/* constructors and destructor */

RobotomyRequestForm::RobotomyRequestForm( void )
	: AForm("RobotomyRequestForm", 45, 72) {

	return ;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target )
	: AForm("RobotomyRequestForm", target, 45, 72) {

	return ;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src )
	: AForm(src.getName(), src.getTarget(), 45, 72) {

	*this = src;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {

	return ;
}

/* copy assignment operator */

RobotomyRequestForm & RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs ) {

	(void)rhs;
	return (*this);
}

/* private member function */

void	RobotomyRequestForm::action( void ) const {

	std::cout << "* drilling noises *" << std::endl;

	if ((rand() % 2) == 0)
		std::cout << "robotomy succeeded" << std::endl;
	else
		std::cout << "robotomy failed" << std::endl;

	return ;
}
