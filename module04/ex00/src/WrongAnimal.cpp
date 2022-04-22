#include "../includes/WrongAnimal.hpp"

/* constructors and destructor */

WrongAnimal::WrongAnimal( void ) {

	std::cout << "~ Default constructor called for WrongAnimal ~" << std::endl;
	this->_type = "WrongAnimal";
	return ;
}

WrongAnimal::WrongAnimal( WrongAnimal const & src ) {

	std::cout << "~ Copy constructor called for WrongAnimal ~" << std::endl;
	*this = src;
	return ;
}

WrongAnimal::~WrongAnimal( void ) {

	std::cout << "~ Destructor called for WrongAnimal ~" << std::endl;
	return ;
}

/* copy assignment operator */

WrongAnimal & WrongAnimal::operator=( WrongAnimal const & rhs ) {

	std::cout << "~ Copy assignment operator called for WrongAnimal ~" << std::endl;
	this->_type = rhs.getType();
	return (*this);
}

/* public member function */

void	WrongAnimal::makeSound( void ) const {

	std::cout << "* WrongAnimalSound *" << std::endl;
	return ;
}

/* getters */

std::string WrongAnimal::getType( void ) const {

	return (this->_type);
}
