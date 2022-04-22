#include "../includes/DiamondTrap.hpp"

/* constructors and destructor */

DiamondTrap::DiamondTrap( void ) : _name("Default"){

	std::cout << "~ Default constructor called for DiamondTrap ~" << std::endl;
	init_vars("Default");
	return ;
}

DiamondTrap::DiamondTrap( std::string name ) : _name(name) {

	std::cout << "~ Parameterized constructor called for DiamondTrap [" << name << "] ~" << std::endl;
	init_vars(name);
	return ;
}

DiamondTrap::DiamondTrap( DiamondTrap const & src ) {

	std::cout << "~ Copy constructor called for DiamondTrap ~" << std::endl;
	*this = src;
	return ;
}

DiamondTrap::~DiamondTrap( void ) {

	std::cout << "~ Destructor called for DiamondTrap [" << this->_name << "] ~" << std::endl;
	return ;
}

/* copy assignment operator */

DiamondTrap & DiamondTrap::operator=( DiamondTrap const & rhs ) {

	std::cout << "~ Copy assignment operator called for DiamondTrap ~" << std::endl;

	ClapTrap::_name =  rhs.getName();
	this->_name = rhs.getDiamondName();
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_attackDamage = rhs.getAttackDamage();

	return (*this);
}

/*  public member functions */

void		DiamondTrap::attack( const std::string & target ) {

	ScavTrap::attack(target);
	return ;
}

void		DiamondTrap::whoAmI( void ) const {

	std::cout << "DiamondTrap name: " << this->_name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::getName() << std::endl;
	return ;
}

std::string	DiamondTrap::getDiamondName( void ) const {

	return (this->_name);
}

/*  private member functions */

void	DiamondTrap::init_vars(std::string name) {

	FragTrap frag;
	ScavTrap scav;

	ClapTrap::_name = name + "_clap_name";	
	this->_hitPoints = frag.getHitPoints();
	this->_energyPoints = scav.getEnergyPoints();
	this->_attackDamage = frag.getAttackDamage();
	return ;
}
