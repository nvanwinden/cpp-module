#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal {

public:

	WrongAnimal( void );
	WrongAnimal( WrongAnimal const & src );
	virtual ~WrongAnimal( void );

	void			makeSound( void ) const;

	std::string		getType( void ) const;

	WrongAnimal &	operator=( WrongAnimal const & rhs );

protected:

	std::string		_type;

};

#endif
