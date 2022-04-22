/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 16:02:24 by nvan-win      #+#    #+#                 */
/*   Updated: 2022/04/07 09:07:19 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"
#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"

int main ( void ) {

	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();

	Weapon club1 = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.attack();
	club1.setType("some other type of club");
	jim.attack();

	Weapon club2 = Weapon("crude spiked club");
	HumanB gary("Gary");
	gary.setWeapon(club2);
	gary.attack();
	club2.setType("some other type of club");
	gary.attack();

	return (0);

}
