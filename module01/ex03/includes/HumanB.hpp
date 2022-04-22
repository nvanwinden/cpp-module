/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 15:49:55 by nvan-win      #+#    #+#                 */
/*   Updated: 2022/04/06 09:26:29 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB {

public:

	HumanB( std::string name );
	~HumanB( void );

	void	setWeapon( Weapon &weaponType );
	void	attack( void ) const;

private:

	std::string const	_name;
	Weapon				*_weaponType;

};

#endif
