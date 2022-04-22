/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 15:47:52 by nvan-win      #+#    #+#                 */
/*   Updated: 2022/04/06 09:29:09 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {

public:

	Weapon( std::string type );
	~Weapon( void );

	std::string const &	getType( void ) const;
	void				setType( std::string type );

private:

	std::string	_type;

};

#endif
