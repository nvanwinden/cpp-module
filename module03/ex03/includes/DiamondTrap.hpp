#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

class DiamondTrap : public FragTrap, public ScavTrap {

public:

	DiamondTrap( void );
	DiamondTrap( std::string name );
	DiamondTrap( DiamondTrap const & src );
	~DiamondTrap( void );

	void			attack( const std::string & target );
	void			whoAmI( void ) const;

	std::string		getDiamondName( void ) const;

	DiamondTrap &	operator=( DiamondTrap const & rhs );

private:

	std::string		_name;

	void			init_vars( std::string name );

};

#endif
