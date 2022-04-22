#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {

public:

	Brain( void );
	Brain( Brain const & src );
	~Brain( void );

	std::string	_ideas[100];

	Brain &	operator=( Brain const & rhs );

private:

};

#endif
