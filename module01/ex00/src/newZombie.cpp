/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newZombie.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 15:05:11 by nvan-win      #+#    #+#                 */
/*   Updated: 2022/04/07 08:43:42 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie* newZombie( std::string name ) {

	Zombie	*newZombie;

	newZombie = new Zombie(name);
	return (newZombie);
}
