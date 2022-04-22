/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 11:07:26 by nvan-win      #+#    #+#                 */
/*   Updated: 2022/04/12 12:25:18 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "math.h"

/* constructors and destructor */

Fixed::Fixed( void ) : _fixedPointNumber(0) {

	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed( const int n ) : _fixedPointNumber(n << this->_numFractionalBits) {

	std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed( const float f ) : _fixedPointNumber(roundf(f * (1 << this->_numFractionalBits))) {

	std::cout << "Float constructor called" << std::endl;
	return ;
}

Fixed::Fixed( Fixed const & src ) {

	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::~Fixed( void ) {

	std::cout << "Destructor called" << std::endl;
	return ;
}

/* member functions */

float	Fixed::toFloat( void ) const {

	return (static_cast<float>(this->_fixedPointNumber) / (1 << this->_numFractionalBits));
}

int		Fixed::toInt( void ) const {

	return (this->_fixedPointNumber >> 8);
}

/* operator overload functions */

Fixed &			Fixed::operator=( Fixed const & rhs ) {

	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPointNumber = rhs.getRawBits();
	return (*this);
}

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs ) {

	o << rhs.toFloat();
	return (o);
}

/* getters and setters */

int		Fixed::getRawBits( void ) const {

	return (this->_fixedPointNumber);
}

void	Fixed::setRawBits( int const raw ) {

	this->_fixedPointNumber = raw;
	return ;
}
