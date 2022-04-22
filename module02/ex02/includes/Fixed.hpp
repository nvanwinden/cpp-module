/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 11:13:08 by nvan-win      #+#    #+#                 */
/*   Updated: 2022/04/12 11:22:37 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#define GREEN		"\033[32;1m"
#define RESET		"\033[0m"

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

	/* Comparison operators */

	bool	operator>( Fixed const & rhs ) const;
	bool	operator<( Fixed const & rhs ) const;
	bool	operator>=( Fixed const & rhs ) const;
	bool	operator<=( Fixed const & rhs ) const;
	bool	operator==( Fixed const & rhs ) const;
	bool	operator!=( Fixed const & rhs ) const;

	/* Arithmetic operators */

	Fixed	operator+( Fixed const & rhs ) const;
	Fixed	operator-( Fixed const & rhs ) const;
	Fixed	operator*( Fixed const & rhs ) const;
	Fixed	operator/( Fixed const & rhs ) const;

	/* Prefix and Postfix */

	Fixed &	operator++( void );
	Fixed	operator++( int );
	Fixed &	operator--( void );
	Fixed	operator--( int );

	static Fixed &			min( Fixed & a, Fixed & b );
	static const Fixed &	min( const Fixed & a, const Fixed & b );
	static Fixed &			max( Fixed & a, Fixed & b );
	static const Fixed &	max( const Fixed & a, const Fixed & b );

private:

	int					_fixedPointNumber;
	static const int	_numFractionalBits = 8;

};

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs );

#endif
