#include "../includes/ClapTrap.hpp"

void	displayPoints(std::string type, std::string name, std::string moment, int points) {

	std::cout << type << " [" << name << "] " << moment << points << std::endl;
	return ;
}

int		main ( void ) {

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

	return (0);
}
