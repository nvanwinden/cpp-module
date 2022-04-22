#include "../includes/Brain.hpp"

/* constructors and destructor */

Brain::Brain( void ) {

	std::cout << "~ Default constructor called for Brain ~" << std::endl;
	return ;
}

Brain::Brain( Brain const & src ) {

	std::cout << "~ Copy constructor called for Brain ~" << std::endl;
	*this = src;
	return ;
}

Brain::~Brain( void ) {

	std::cout << "~ Destructor called for Brain ~" << std::endl;
	return ;
}

/* copy assignment operator */

Brain & Brain::operator=( Brain const & rhs ) {

	std::cout << "~ Copy assignment operator called for Brain ~" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = rhs._ideas[i];
	return (*this);
}
