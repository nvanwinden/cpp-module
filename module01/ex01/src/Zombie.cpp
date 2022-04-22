/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 15:14:13 by nvan-win      #+#    #+#                 */
/*   Updated: 2022/04/06 08:46:44 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie( void ) {

	return ;
}

Zombie::~Zombie( void ) {

	std::cout << "[" << this->_num  << "] " << this->_name << ": Destroyed" << std::endl;
	return ;
}

void Zombie::announce( void ) const {

	std::cout << "[" << this->_num  << "] " << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void Zombie::setNum(int num) {

	this->_num = num;
}

void Zombie::setName(std::string name) {

	this->_name = name;
}
