#ifndef DOG_HPP
# define DOG_HPP

#include "../includes/AAnimal.hpp"

class Dog : public AAnimal {

public:

	Dog( void );
	Dog( Dog const & src );
	~Dog( void );

	void	makeSound( void ) const;

	Brain *	getBrain( void ) const;

	Dog &	operator=( Dog const & rhs );

private:

	Brain	*_brain;

};

#endif
