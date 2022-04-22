/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 16:36:11 by nvan-win      #+#    #+#                 */
/*   Updated: 2022/04/06 09:52:40 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

Harl::Harl( void ) {

	return ;
}

Harl::~Harl ( void ) {

	return ;
}

void Harl::complain( std::string level ) {

	void (Harl::*type[]) () = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*type[i])();
			return ;
		}
	}
	std::cout << "You are supposed to complain, Harl!" << std::endl;
	return ;
}

void Harl::debug( void ) {

	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
	return ;
}

void Harl::info( void ) {

	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	return ;
}

void Harl::warning( void ) {

	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
	return ;
}

void Harl::error( void ) {

	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	return ;
}
