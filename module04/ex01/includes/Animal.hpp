#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include "../includes/Brain.hpp"
#include <iostream>

#define GREEN	"\033[0;32m"
#define RESET	"\033[0m"

class Animal {

public:

	Animal( void );
	Animal( Animal const & src );
	virtual ~Animal( void );

	virtual void	makeSound( void ) const;

	std::string		getType( void ) const;

	Animal &		operator=( Animal const & rhs );

protected:

	std::string		_type;

};

#endif
