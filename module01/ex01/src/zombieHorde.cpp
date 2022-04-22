/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 15:22:28 by nvan-win      #+#    #+#                 */
/*   Updated: 2022/03/17 15:22:31 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie	*zombieHorde( int N, std::string name ) {

	Zombie	*zombieHorde;

	zombieHorde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zombieHorde[i].setNum(i);
		zombieHorde[i].setName(name);
		zombieHorde[i].announce();
	}
	return (zombieHorde);
}
