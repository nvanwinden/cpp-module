#include "../includes/PresidentialPardonForm.hpp"

/* constructors and destructor */

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("PresidentialPardonForm", 5, 25) {

	return ;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("PresidentialPardonForm", target, 5, 25) {

	return ;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src ) : AForm(src.getName(), src.getTarget(), 5, 25) {

	*this = src;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {

	return ;
}

/* copy assignment operator */

PresidentialPardonForm & PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs ) {

	(void)rhs;
	return (*this);
}

/* private member function */

void	PresidentialPardonForm::action( void ) const {

	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;

	return ;
}
