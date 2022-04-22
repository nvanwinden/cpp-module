#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

#define GREEN	"\033[0;32m"
#define BKGRND	"\033[38;5;0;48;5;231m"
#define RESET	"\033[0m"

class ClapTrap {

public:

	ClapTrap( void );
	ClapTrap( std::string name );
	ClapTrap( ClapTrap const & src );
	~ClapTrap( void );

	void			attack( const std::string & target );
	void			takeDamage( unsigned int amount );
	void			beRepaired( unsigned int amount );

	std::string		getName( void ) const ;
	unsigned int	getHitPoints( void ) const ;
	unsigned int	getEnergyPoints( void ) const ;
	unsigned int	getAttackDamage( void ) const ;

	ClapTrap &		operator=( ClapTrap const & rhs );

protected:

	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

	void			displayMessage(std::string name, std::string message) const;

};

#endif
