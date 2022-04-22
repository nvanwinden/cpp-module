#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

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
