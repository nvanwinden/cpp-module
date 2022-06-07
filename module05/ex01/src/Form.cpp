#include "../includes/Form.hpp"

/* constructors and destructor */

Form::Form( void ) : _name("default"), _exec(0), _sign(0), _signed(false) {

	return ;
}

Form::Form( std::string const name, unsigned int exec, unsigned int sign)
	: _name(name), _exec(exec), _sign(sign), _signed(false) {

	std::cout << *this << std::endl;

	if (this->_exec < HIGHEST_GRADE || this->_sign < HIGHEST_GRADE)
		throw (GradeTooHighException());
	else if (this->_exec > LOWEST_GRADE || this->_sign > LOWEST_GRADE)
		throw (GradeTooLowException());

	return ;
}

Form::Form( Form const & src )
	: _name(src.getName()), _exec(src.getExec()), _sign(src.getSign()) {

	*this = src;
	return ;
}

Form::~Form( void ) {

	return ;
}

/* copy assignment operator */

Form & Form::operator=( Form const & rhs ) {

	this->_signed = rhs.getSigned();
	return (*this);
}

/* public member function */

void	Form::beSigned( Bureaucrat & bureaucrat ) {

	if (bureaucrat.getGrade() <= this->_sign)
		this->_signed = true;
	else
		throw (GradeTooLowException());
	
	std::cout << *this << std::endl;
	return ;
}

/* getters */

std::string const	Form::getName( void ) const {

	return (this->_name);
}

unsigned int		Form::getExec( void ) const {

	return (this->_exec);
}

unsigned int		Form::getSign( void ) const {

	return (this->_sign);
}

bool				Form::getSigned( void ) const {

	return (this->_signed);
}

/* exceptions */

const char*	Form::GradeTooHighException::what() const throw() {

	return ("Form::GradeTooHighException");
}
	
const char*	Form::GradeTooLowException::what() const throw() {

	return ("Form::GradeTooLowException");
}

/* insertion operator overload */

std::ostream &	operator<<( std::ostream & o, Form const & rhs ) {

	o << "Form name: " << rhs.getName() << std::endl <<
	"Grade exec: " << rhs.getExec() << std::endl <<
	"Grade sign: " << rhs.getSign() << std::endl <<
	"Signed: " << rhs.getSigned() << std::endl;

	return (o);
}
