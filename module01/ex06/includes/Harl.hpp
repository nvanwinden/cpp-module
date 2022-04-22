/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 16:37:57 by nvan-win      #+#    #+#                 */
/*   Updated: 2022/03/18 10:06:10 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl {

public:

	Harl( void );
	~Harl( void );

	void complain( std::string level );

private:

	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

};

#endif
