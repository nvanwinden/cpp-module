#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include "../includes/Brain.hpp"
#include <iostream>

#define GREEN	"\033[0;32m"
#define BKGRND	"\033[38;5;0;48;5;231m"
#define RESET	"\033[0m"

class AAnimal {

public:

	AAnimal( void );
	AAnimal( AAnimal const & src );
	virtual ~AAnimal( void );

	virtual void	makeSound( void ) const = 0;

	std::string		getType( void ) const;

	AAnimal &		operator=( AAnimal const & rhs );

protected:

	std::string		_type;

};

#endif
