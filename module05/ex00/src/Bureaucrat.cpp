#include "../includes/Bureaucrat.hpp"

/* constructors and destructor */

Bureaucrat::Bureaucrat( void ) : _name("default"), _grade(0){

	return ;
}

Bureaucrat::Bureaucrat( std::string const name, unsigned int grade ) : _name(name), _grade(grade) {

	std::cout << *this << std::endl;

	if (grade < HIGHEST_GRADE)
		throw (GradeTooHighException());
	else if (grade > LOWEST_GRADE)
		throw (GradeTooLowException());

	return ;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) : _name(src.getName()) {

	*this = src;
	return ;
}

Bureaucrat::~Bureaucrat( void ) {

	return ;
}

/* copy assignment operator */

Bureaucrat & Bureaucrat::operator=( Bureaucrat const & rhs ) {

	this->_grade = rhs.getGrade();
	return (*this);
}

/* getters */

std::string const	Bureaucrat::getName( void ) const {

	return (this->_name);
}

unsigned int		Bureaucrat::getGrade( void ) const {

	return (this->_grade);
}

/* exceptions */

const char * 	Bureaucrat::GradeTooHighException::what() const throw() {

	return ("Bureaucrat::GradeTooHighException");
}

const char *	Bureaucrat::GradeTooLowException::what() const throw() {

	return ("Bureaucrat::GradeTooLowException");
}

/* public member functions */

void	Bureaucrat::incrementGrade( void ) {

	if ((this->_grade - 1) < HIGHEST_GRADE)
		throw (Bureaucrat::GradeTooHighException());

	this->_grade -= 1;
	return ;
}

void	Bureaucrat::decrementGrade( void ) {

	if ((this->_grade + 1) > LOWEST_GRADE)
		throw (Bureaucrat::GradeTooLowException());

	this->_grade += 1;
	return ;
}

/* insertion operator overload */

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs ) {

	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return (o);
}
