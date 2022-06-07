#include "../includes/AForm.hpp"

/* constructors and destructor */

AForm::AForm( void ) : _name("default"), _target("default"), _exec(0), _sign(0), _signed(false) {

	return ;
}

AForm::AForm( std::string const name, unsigned int exec, unsigned int sign )
	: _name(name), _exec(exec), _sign(sign), _signed(false) {

	std::cout << *this << std::endl;

	if (this->_exec < HIGHEST_GRADE || this->_sign < HIGHEST_GRADE)
		throw (GradeTooHighException());
	else if (this->_exec > LOWEST_GRADE || this->_sign > LOWEST_GRADE)
		throw (GradeTooLowException());

	return ;
}

AForm::AForm( std::string const name, std::string const target, unsigned int exec, unsigned int sign)
	: _name(name), _target(target), _exec(exec), _sign(sign), _signed(false) {

	std::cout << *this << std::endl;

	if (this->_exec < HIGHEST_GRADE || this->_sign < HIGHEST_GRADE)
		throw (GradeTooHighException());
	else if (this->_exec > LOWEST_GRADE || this->_sign > LOWEST_GRADE)
		throw (GradeTooLowException());

	return ;
}

AForm::AForm( AForm const & src ) : _name(src.getName()), _exec(src.getExec()), _sign(src.getSign()) {

	*this = src;
	return ;
}

AForm::~AForm( void ) {

	return ;
}

/* copy assignment operator */

AForm & AForm::operator=( AForm const & rhs ) {

	this->_signed = rhs.getSigned();
	return (*this);
}

/* public member function */

void	AForm::beSigned( Bureaucrat & bureaucrat ) {

	if (bureaucrat.getGrade() <= this->_sign)
		this->_signed = true;
	else
		throw (GradeTooLowException());
	return ;
}

void	AForm::execute( Bureaucrat const & executor ) const {

	if (!getSigned())
		throw(FormNotSignedException());
	if (executor.getGrade() > getExec())
		throw(GradeTooLowException());

	action();

	return ;
}

/* getters */

std::string const	AForm::getName( void ) const {

	return (this->_name);
}

std::string const	AForm::getTarget( void ) const {

	return (this->_target);
}

unsigned int		AForm::getExec( void ) const {

	return (this->_exec);
}

unsigned int		AForm::getSign( void ) const {

	return (this->_sign);
}

bool				AForm::getSigned( void ) const {

	return (this->_signed);
}

/* exceptions */

const char*	AForm::GradeTooHighException::what() const throw() {

	return ("AForm::GradeTooHighException");
}
	
const char*	AForm::GradeTooLowException::what() const throw() {

	return ("Form::GradeTooLowException");
}

const char*	AForm::FormNotSignedException::what() const throw() {

	return ("Form::FormNotSignedException");
}

/* insertion operator overload */

std::ostream &	operator<<( std::ostream & o, AForm const & rhs ) {

	o << "Form name: " << rhs.getName() << std::endl <<
	"Target name: " << rhs.getTarget() << std::endl <<
	"Grade exec: " << rhs.getExec() << std::endl <<
	"Grade sign: " << rhs.getSign() << std::endl <<
	"Signed: " << rhs.getSigned() << std::endl;

	return (o);
}
