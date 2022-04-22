#include "../includes/Cat.hpp"

/* constructors and destructor */

Cat::Cat( void ) {

	std::cout << "~ Default constructor called for Cat ~" << std::endl;
    this->_type = "Cat";
	return ;
}

Cat::Cat( Cat const & src ) {

	std::cout << "~ Copy constructor called for Cat ~" << std::endl;
	*this = src;
	return ;
}

Cat::~Cat( void ) {

	std::cout << "~ Destructor called for Cat ~" << std::endl;
	return ;
}

/* copy assignment operator */

Cat & Cat::operator=( Cat const & rhs ) {

	std::cout << "~ Copy assignment operator called for Cat ~" << std::endl;
	this->_type = rhs.getType();
	return (*this);
}

/* public member function */

void	Cat::makeSound( void ) const {

	std::cout << "* meow *" << std::endl;
	return ;
}
