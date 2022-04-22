#ifndef CAT_HPP
# define CAT_HPP

#include "../includes/Animal.hpp"

class Cat : public Animal {

public:

	Cat( void );
	Cat( Cat const & src );
	~Cat( void );

	void	makeSound( void ) const;

	Brain *	getBrain( void ) const;

	Cat &	operator=( Cat const & rhs );

private:

	Brain	*_brain;

};

#endif
