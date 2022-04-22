#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

#include "../includes/WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

public:

	WrongCat( void );
	WrongCat( WrongCat const & src );
	~WrongCat( void );

	void		makeSound( void ) const;

	WrongCat &	operator=( WrongCat const & rhs );

private:

};

#endif
