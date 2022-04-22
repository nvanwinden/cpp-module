#include "../includes/Dog.hpp"

/* constructors and destructor */

Dog::Dog( void ) {

	std::cout << "~ Default constructor called for Dog ~" << std::endl;
	this->_type = "Dog";
	return ;
}

Dog::Dog( Dog const & src ) {

	std::cout << "~ Copy constructor called for Dog ~" << std::endl;
	*this = src;
	return ;
}

Dog::~Dog( void ) {

	std::cout << "~ Destructor called for Dog ~" << std::endl;
	return ;
}

/* copy assignment operator */

Dog & Dog::operator=( Dog const & rhs ) {

	std::cout << "~ Copy assignment operator called for Dog ~" << std::endl;
	this->_type = rhs.getType();
	return (*this);
}

/* public member function */

void	Dog::makeSound( void ) const {

	std::cout << "* bark *" << std::endl;
	return ;
}
