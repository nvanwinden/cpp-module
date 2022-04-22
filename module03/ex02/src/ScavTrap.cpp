#include "../includes/ScavTrap.hpp"

/* constructors and destructor */

ScavTrap::ScavTrap( void ) {

	std::cout << "~ Default constructor called for ScavTrap ~" << std::endl;
	this->_name = "Default";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	return ;
}

ScavTrap::ScavTrap( std::string name ) {

	std::cout << "~ Parameterized constructor called for ScavTrap [" << name << "] ~" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap( ScavTrap const & src ) {

	std::cout << "~ Copy constructor called for ScavTrap ~" << std::endl;
	*this = src;
	return ;
}

ScavTrap::~ScavTrap( void ) {

	std::cout << "~ Destructor called for ScavTrap [" << this->_name << "] ~" << std::endl;
	return ;
}

/* copy assignment operator */

ScavTrap & ScavTrap::operator=( ScavTrap const & rhs ) {

	std::cout << "~ Copy assignment operator called for ScavTrap ~" << std::endl;

	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_attackDamage = rhs.getAttackDamage();

	return (*this);
}

/*  public member functions */

void	ScavTrap::attack( const std::string& target ) {

	if (this->_hitPoints == 0)
		return (displayMessage(this->_name, " is dead and unable to attack"));
	if (this->_energyPoints == 0)
		return (displayMessage(this->_name, " has no energy points left to attack"));
	std::cout << "ScavTrap [" << this->_name << "] attacks [" << target <<
	"] causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
	return ;
}

void	ScavTrap::guardGate( void ) const {

	return (displayMessage(this->_name, " is now in gate keeper mode"));
}
