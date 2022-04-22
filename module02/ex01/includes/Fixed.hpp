/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 11:06:54 by nvan-win      #+#    #+#                 */
/*   Updated: 2022/04/12 11:09:50 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

public:

	Fixed( void );
	Fixed( const int n );
	Fixed( const float f );
	Fixed( Fixed const & src );
	~Fixed ( void );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

	Fixed &	operator=( Fixed const & rhs );

private:

	int					_fixedPointNumber;
	static const int	_numFractionalBits = 8;

};

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs );

#endif
