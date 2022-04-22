/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 16:01:54 by nvan-win      #+#    #+#                 */
/*   Updated: 2022/04/07 09:03:44 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name) {

	return ;
}

HumanB::~HumanB( void ) {

	return ;
}

void HumanB::setWeapon( Weapon &weaponType ) {

	this->_weaponType = &weaponType;
	return ;
}

void HumanB::attack( void ) const {

	if (this->_weaponType == NULL)
	{
		std::cout << this->_name << " has no weapon and cannot attack" << std::endl;
		return ;
	}
	std::cout << this->_name << " attacks with their " << this->_weaponType->getType() << std::endl;
	return ;
}
