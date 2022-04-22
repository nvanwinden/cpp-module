/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 15:06:56 by nvan-win      #+#    #+#                 */
/*   Updated: 2022/04/06 08:01:26 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie( std::string name ) : _name(name) {

	this->announce();
	return ;
}

Zombie::~Zombie( void ) {

	std::cout << this->_name << ": Destroyed" << std::endl;
	return ;
}

void	Zombie::announce( void ) const {

	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}
