/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 14:59:58 by nvan-win      #+#    #+#                 */
/*   Updated: 2022/04/06 08:01:15 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {

public:

	Zombie( std::string name );
	~Zombie( void );

private:

	void				announce( void ) const;
	std::string const	_name;

};

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );

#endif
