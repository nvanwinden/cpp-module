#include "../includes/Animal.hpp"

/* constructors and destructor */

Animal::Animal( void ) : _type("Animal") {

	std::cout << "~ Default constructor called for Animal ~" << std::endl;
	return ;
}

Animal::Animal( Animal const & src ) {

	std::cout << "~ Copy constructor called for Animal ~" << std::endl;
	*this = src;
	return ;
}

Animal::~Animal( void ) {

	std::cout << "~ Destructor called for Animal ~" << std::endl;
	return ;
}

/* copy assignment operator */

Animal & Animal::operator=( Animal const & rhs ) {

	std::cout << "~ Copy assignment operator called for Animal ~" << std::endl;
	this->_type = rhs.getType();
	return (*this);
}

/* public member function */

void	Animal::makeSound( void ) const {

	std::cout << "* silence *" << std::endl;
	return ;
}

/* getters */

std::string Animal::getType( void ) const {

	return (this->_type);
}
