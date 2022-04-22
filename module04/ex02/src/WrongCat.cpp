#include "../includes/WrongCat.hpp"

/* constructors and destructor */

WrongCat::WrongCat( void ) {

	std::cout << "~ Default constructor called for WrongCat ~" << std::endl;
	this->_type = "WrongCat";
	return ;
}

WrongCat::WrongCat( WrongCat const & src ) {

	std::cout << "~ Copy constructor called for WrongCat ~" << std::endl;
	*this = src;
	return ;
}

WrongCat::~WrongCat( void ) {

	std::cout << "~ Destructor called for WrongCat ~" << std::endl;
	return ;
}

/* copy assignment operator */

WrongCat & WrongCat::operator=( WrongCat const & rhs ) {

	std::cout << "~ Copy assignment operator called for WrongCat ~" << std::endl;
	this->_type = rhs.getType();
	return (*this);
}

/* public member functions */

void	WrongCat::makeSound( void ) const {

	std::cout << "* meow *" << std::endl;
	return ;
}
