#include "../includes/DiamondTrap.hpp"

void	displayPoints(std::string type, std::string name, std::string moment, int points) {

	std::cout << type << " [" << name << "] " << moment << points << std::endl;
	return ;
}

int main ( void ) {

	/* Tests ex00 */

	std::cout << std::endl << BKGRND << "== TESTS ex00 ==" << RESET << std::endl;

	std::cout << std::endl << GREEN << "• Creating 3 ClapTraps •" << RESET << std::endl << std::endl;

	ClapTrap logan = ClapTrap("Logan");
	ClapTrap fargo = ClapTrap("Fargo");
	ClapTrap olav = ClapTrap("Olav");

	std::cout << std::endl << GREEN << "• Logan attacks Fargo •" << RESET << std::endl << std::endl;
	displayPoints("Energy points", logan.getName(), "before: ", logan.getEnergyPoints());
	logan.attack(fargo.getName());
	displayPoints("Energy points", logan.getName(), "after: ", logan.getEnergyPoints());

	std::cout << std::endl << GREEN << "• Fargo is taking damage •" << RESET << std::endl << std::endl;
	displayPoints("Hit points", fargo.getName(), "before: ", fargo.getHitPoints());
	fargo.takeDamage(2);
	displayPoints("Hit points", fargo.getName(), "after:", fargo.getHitPoints());

	std::cout << std::endl << GREEN << "• Logan attacks Fargo again •" << RESET << std::endl << std::endl;
	displayPoints("Energy points", logan.getName(), "before: ", logan.getEnergyPoints());
	logan.attack(fargo.getName());
	displayPoints("Energy points", logan.getName(), "after: ", logan.getEnergyPoints());

	std::cout << std::endl << GREEN << "• Fargo is taking damage •" << RESET << std::endl << std::endl;
	displayPoints("Hit points", fargo.getName(), "before: ", fargo.getHitPoints());
	fargo.takeDamage(3);
	displayPoints("Hit points", fargo.getName(), "after: ", fargo.getHitPoints());

	std::cout << std::endl << GREEN << "• Fargo is repairing themself •" << RESET << std::endl << std::endl;
	displayPoints("Energy points", fargo.getName(), "before: ", fargo.getEnergyPoints());
	displayPoints("Hit points", fargo.getName(), "before: ", fargo.getHitPoints());
	fargo.beRepaired(5);
	displayPoints("Energy points", fargo.getName(), "after: ", fargo.getEnergyPoints());
	displayPoints("Hit points", fargo.getName(), "after: ", fargo.getHitPoints());

	std::cout << std::endl << GREEN << "• Logan is taking a big hit and dies •" << RESET << std::endl << std::endl;
	displayPoints("Hit points", logan.getName(), "before: ", logan.getHitPoints());
	logan.takeDamage(12);
	displayPoints("Hit points", logan.getName(), "after: ", logan.getHitPoints());

	std::cout << std::endl << GREEN << "• Just to proof that Logan cannot take any more damage •" << RESET << std::endl << std::endl;
	logan.takeDamage(9);

	std::cout << std::endl << GREEN << "• Just to proof that Logan is dead and unable to attack •" << RESET << std::endl << std::endl;
	logan.attack("Fargo");

	std::cout << std::endl << GREEN << "• Fargo is using up all their energy points •" << RESET << std::endl << std::endl;
	displayPoints("Energy points", fargo.getName(), "before: ", fargo.getEnergyPoints());
	while (fargo.getEnergyPoints() != 0)
		fargo.attack(olav.getName());
	displayPoints("Energy points", fargo.getName(), "after: ", fargo.getEnergyPoints());

	std::cout << std::endl << GREEN << "• Just to proof Fargo is unable to attack and repair with zero enery points left •" << RESET << std::endl << std::endl;
	fargo.attack(olav.getName());
	fargo.beRepaired(5);

	std::cout << std::endl;

	/* Tests ex01 */

	std::cout << std::endl << BKGRND << "== TESTS ex01 ==" << RESET << std::endl;

	std::cout << std::endl << GREEN << "• Now we create a new ScavTrap •" << RESET << std::endl << std::endl;
	ScavTrap bleepbloop = ScavTrap("BleepBloop");

	std::cout << std::endl << GREEN << "• ScavTrap BleepBloop inherits attributes from ClapTrap but are initialized to different values •" << RESET << std::endl << std::endl;
	std::cout << "Name: " << bleepbloop.getName() << std::endl;
	std::cout << "Energy points: " << bleepbloop.getEnergyPoints() << std::endl;
	std::cout << "Hit points: " << bleepbloop.getHitPoints() << std::endl;
	std::cout << "Attack damage: " <<bleepbloop.getAttackDamage() << std::endl;

	std::cout << std::endl << GREEN << "• A ScavTrap has its own special capacity called Gate Keeper Mode •" << RESET << std::endl << std::endl;
	bleepbloop.guardGate();

	std::cout << std::endl << GREEN << "• ScavTrap's attack function prints a different message •" << RESET << std::endl << std::endl;
	bleepbloop.attack("Olav");

	std::cout << std::endl << GREEN << "• ScavTrap inherits takeDamage() and beRepaired() from ClapTrap •" << RESET << std::endl << std::endl;
	displayPoints("Hit points", bleepbloop.getName(), "before: ", bleepbloop.getHitPoints());
	bleepbloop.takeDamage(10);
	displayPoints("Hit points", bleepbloop.getName(), "after: ", bleepbloop.getHitPoints());
	bleepbloop.beRepaired(5);
	displayPoints("Hit points", bleepbloop.getName(), "after: ", bleepbloop.getHitPoints());


	/* Tests ex02 */

	std::cout << std::endl << BKGRND << "== TESTS ex02 ==" << RESET << std::endl;

	std::cout << std::endl << GREEN << "• Now we create a new FragTrap •" << RESET << std::endl << std::endl;
	FragTrap fr4g("Fr4g"); 

	std::cout << std::endl << GREEN << "• FragTrap Fr4g also inherits attributes from ClapTrap but are initialized to different values •" << RESET << std::endl << std::endl;
	std::cout << "Name: " << fr4g.getName() << std::endl;
	std::cout << "Energy points: " << fr4g.getEnergyPoints() << std::endl;
	std::cout << "Hit points: " << fr4g.getHitPoints() << std::endl;
	std::cout << "Attack damage: " <<fr4g.getAttackDamage() << std::endl;

	std::cout << std::endl << GREEN << "• A FragTrap has its own special capacity called High Fives Guys •" << RESET << std::endl << std::endl;
	fr4g.highFivesGuys();

	std::cout << std::endl << GREEN << "• FragTrap's attack function prints a different message •" << RESET << std::endl << std::endl;
	fr4g.attack(bleepbloop.getName());

	std::cout << std::endl << GREEN << "• FragTrap inherits takeDamage() and beRepaired() from ClapTrap •" << RESET << std::endl << std::endl;
	displayPoints("Hit points", fr4g.getName(), "before: ", fr4g.getHitPoints());
	fr4g.takeDamage(10);
	displayPoints("Hit points", fr4g.getName(), "after: ", fr4g.getHitPoints());
	fr4g.beRepaired(5);
	displayPoints("Hit points", fr4g.getName(), "after: ", fr4g.getHitPoints());

	/* Tests ex03 */

	std::cout << std::endl << BKGRND << "== TESTS ex03 ==" << RESET << std::endl;
	std::cout << std::endl << GREEN << "• Now we create a new DiamondTrap •" << RESET << std::endl << std::endl;

	DiamondTrap diamond = DiamondTrap("Diamond");

	std::cout << std::endl << GREEN << "• DiamondTrap inherits from both Fragtrap and ScavTrap •" << RESET << std::endl << std::endl;

	diamond.guardGate();
	diamond.highFivesGuys();

	std::cout << std::endl << GREEN << "• And can access the name of both ClapTrap and DiamondTrap •" << RESET << std::endl << std::endl;
	diamond.whoAmI();

	std::cout << std::endl << GREEN << "• DiamondTrap inherits the attack() function from ScavTrap •" << RESET << std::endl << std::endl;
	diamond.attack("fr4g");

	std::cout << std::endl << GREEN << "• DiamondTrap's attributes are picked from FragTrap and ScavTrap •" << RESET << std::endl << std::endl;
	std::cout << "Energy points [ScavTrap = 50]: " << diamond.getEnergyPoints() << std::endl;
	std::cout << "Hit points [FragTrap = 100]: " << diamond.getHitPoints() << std::endl;
	std::cout << "Attack damage [FragTrap = 30]: " << diamond.getAttackDamage() << std::endl; // is now 20, gets overwritten, should be 30

	std::cout << std::endl;

	return (0);
}
