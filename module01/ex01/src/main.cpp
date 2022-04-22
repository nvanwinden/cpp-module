/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 15:20:28 by nvan-win      #+#    #+#                 */
/*   Updated: 2022/04/06 08:57:19 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int main ( void ) {

	Zombie	*firstZombie;
	int		num;

	num = 10;
	firstZombie = zombieHorde(num, "Nilo");

	std::cout << std::endl;
	firstZombie->announce();
	std::cout << std::endl;

	delete [] firstZombie;

	return (0);
}
