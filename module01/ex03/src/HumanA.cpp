/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 16:02:17 by nvan-win      #+#    #+#                 */
/*   Updated: 2022/04/06 09:25:50 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weaponType ) : _name(name), _weaponType(weaponType) {
	
	return ;
}

HumanA::~HumanA( void ) {

	return ;
}

void	HumanA::attack( void ) const {

	std::cout << this->_name << " attacks with their " << this->_weaponType.getType() << std::endl;
	return ;
}
