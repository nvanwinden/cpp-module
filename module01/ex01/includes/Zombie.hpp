/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 15:11:29 by nvan-win      #+#    #+#                 */
/*   Updated: 2022/04/06 08:43:12 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {

public:

	Zombie( void );
	~Zombie( void );
	
	void		announce( void ) const;
	void		setName( std::string name );
	void		setNum( int num );

private:

	std::string	_name;
	int			_num;

};

Zombie	*zombieHorde( int N, std::string name );

#endif
