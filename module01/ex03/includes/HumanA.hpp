/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 15:49:48 by nvan-win      #+#    #+#                 */
/*   Updated: 2022/04/06 09:25:11 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA {

public:

	HumanA( std::string name, Weapon& weaponType );
	~HumanA( void );

	void	attack( void ) const;

private:

	std::string const	_name;
	Weapon				&_weaponType;

};

#endif
