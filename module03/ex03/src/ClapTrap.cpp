#include "../includes/ClapTrap.hpp"

/* constructors and destructor */

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {

	std::cout << "~ Default constructor called for ClapTrap ~" << std::endl;
	return;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {

	std::cout << "~ Parameterized constructor called for ClapTrap [" << name << "] ~" << std::endl;
	return ;
}

ClapTrap::ClapTrap( ClapTrap const & src ) {

	std::cout << "~ Copy constructor called for Claptrap ~" << std::endl;
	*this = src;
	return ;
}

ClapTrap::~ClapTrap( void ) {

	std::cout << "~ Destructor called for ClapTrap [" << this->_name << "] ~" << std::endl;
	return ;
}

/* copy assignment operator */

ClapTrap & ClapTrap::operator=( ClapTrap const & rhs ) {

	std::cout << "~ Copy assignment operator called for ClapTrap ~" << std::endl;

	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_attackDamage = rhs.getAttackDamage();

	return (*this);
}

/*  protected member function */

void	ClapTrap::displayMessage(std::string name, std::string message) const {

	std::cout << "[" << name << "]" << message << std::endl;
	return ;
}

/*  public member functions */

void	ClapTrap::attack( const std::string& target ) {

	if (this->_hitPoints == 0)
		return (displayMessage(this->_name, " is dead and unable to attack"));
	if (this->_energyPoints == 0)
		return (displayMessage(this->_name, " has no energy points left to attack"));
	std::cout << "ClapTrap [" << this->_name << "] attacks [" << target <<
	"] causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
	return ;
}

void	ClapTrap::takeDamage( unsigned int amount ) {

	if (this->_hitPoints == 0)
		return (displayMessage(this->_name, " is already dead"));
	std::cout << "[" << this->_name << "] is taking " << amount << " damage" << std::endl;
	if (amount > this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	return ;
}

void	ClapTrap::beRepaired( unsigned int amount ) {

	if (this->_energyPoints == 0)
		return (displayMessage(this->_name, " has no energy points left to repair themself"));
	std::cout << "[" << this->_name << "] repairs themself with " << amount << " points" << std::endl;
	this->_hitPoints += amount;
	this->_energyPoints -= 1;
	return ;
}

/* Getters */

std::string	ClapTrap::getName( void ) const {

	return (this->_name);
}

unsigned int	ClapTrap::getHitPoints( void ) const {

	return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints( void ) const {

	return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage( void ) const {

	return (this->_attackDamage);
}
