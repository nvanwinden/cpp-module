/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 15:04:59 by nvan-win      #+#    #+#                 */
/*   Updated: 2022/04/07 08:41:16 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int	main (void) {

	std::srand(time(0));
	std::string	zombieTypes[10] = {"Slimy", "Grubber", "David", "Grimer", "Eyeball", "Sludge", "Maggot", "Chewer", "Crow", "Gutsman"};

	randomChump(zombieTypes[std::rand() % 10]);

	Zombie		zombieStack("StackZombie");
	Zombie		*zombieHeap = newZombie("HeapZombie");

	delete zombieHeap;

	return (0);
}
