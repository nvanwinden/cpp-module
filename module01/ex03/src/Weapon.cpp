/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 16:03:50 by nvan-win      #+#    #+#                 */
/*   Updated: 2022/04/06 09:28:24 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon( std::string type ) : _type(type) {

	return ;
}

Weapon::~Weapon( void ) {

	return;
}

void Weapon::setType( std::string type ) {

	this->_type = type;
	return ;
}

std::string const &Weapon::getType( void ) const {

	return (this->_type);
}
