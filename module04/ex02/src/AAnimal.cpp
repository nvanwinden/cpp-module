#include "../includes/AAnimal.hpp"

/* constructors and destructor */

AAnimal::AAnimal( void ) : _type("Nameless") {

	std::cout << "~ Default constructor called for Animal ~" << std::endl;
	return ;
}

AAnimal::AAnimal( AAnimal const & src ) {

	std::cout << "~ Copy constructor called for Animal ~" << std::endl;
	*this = src;
	return ;
}

AAnimal::~AAnimal( void ) {

	std::cout << "~ Destructor called for Animal ~" << std::endl;
	return ;
}

/* copy assignment operator */

AAnimal & AAnimal::operator=( AAnimal const & rhs ) {

	std::cout << "~ Copy assignment operator called for Animal ~" << std::endl;
	this->_type = rhs.getType();
	return (*this);
}

/* getters */

std::string AAnimal::getType( void ) const {

	return (this->_type);
}
