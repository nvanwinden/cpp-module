#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap {

public:

	FragTrap( void );
	FragTrap( std::string name );
	FragTrap( FragTrap const & src );
	~FragTrap( void );

	void		attack( const std::string & target );
	void		highFivesGuys( void ) const;

	FragTrap &	operator=( FragTrap const & rhs );

private:

};

#endif
