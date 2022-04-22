#include "../includes/FragTrap.hpp"

/* constructors and destructor */

FragTrap::FragTrap( void ) {

	std::cout << "~ Default constructor called for FragTrap ~" << std::endl;
	this->_name = "Default";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	return ;
}

FragTrap::FragTrap( std::string name ) {

	std::cout << "~ Parameterized constructor called for FragTrap [" << name << "] ~" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap( FragTrap const & src ) {

	std::cout << "~ Copy constructor called for FragTrap ~" << std::endl;
	*this = src;
	return ;
}

FragTrap::~FragTrap( void ) {

	std::cout << "~ Destructor called for FragTrap [" << this->_name << "] ~" << std::endl;
	return ;
}

/* copy assignment operator */

FragTrap & FragTrap::operator=( FragTrap const & rhs ) {

	std::cout << "~ Copy assignment operator called for FragTrap ~" << std::endl;

	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_attackDamage = rhs.getAttackDamage();

	return (*this);
}

/*  public member functions */

void	FragTrap::attack( const std::string& target ) {

	if (this->_hitPoints == 0)
		return (displayMessage(this->_name, " is dead and unable to attack"));
	if (this->_energyPoints == 0)
		return (displayMessage(this->_name, " has no energy points left to attack"));
	std::cout << "FragTrap [" << this->_name << "] attacks [" << target <<
	"] causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
	return ;
}

void	FragTrap::highFivesGuys( void ) const {

	return (displayMessage(this->_name, " says: give me five!"));
}
