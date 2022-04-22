/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 11:23:11 by nvan-win      #+#    #+#                 */
/*   Updated: 2022/04/12 12:28:01 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "math.h"

/* constructors and destructor */

Fixed::Fixed( void ) : _fixedPointNumber(0) {

	return ;
}

Fixed::Fixed( const int n ) : _fixedPointNumber(n << this->_numFractionalBits) {

	return ;
}

Fixed::Fixed( const float f ) : _fixedPointNumber(roundf(f * (1 << this->_numFractionalBits))) {

	return ;
}

Fixed::Fixed( Fixed const & src ) {

	*this = src;
	return ;
}

Fixed::~Fixed( void ) {

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

Fixed &	Fixed::operator=( Fixed const & rhs ) {

	this->_fixedPointNumber = rhs.getRawBits();
	return (*this);
}

bool	Fixed::operator>( Fixed const & rhs ) const {

	return (this->_fixedPointNumber > rhs._fixedPointNumber);
}

bool	Fixed::operator<( Fixed const & rhs ) const {

	return (this->_fixedPointNumber < rhs._fixedPointNumber);
}

bool	Fixed::operator>=( Fixed const & rhs ) const {

	return (this->_fixedPointNumber >= rhs._fixedPointNumber);
}

bool	Fixed::operator<=( Fixed const & rhs ) const {

	return (this->_fixedPointNumber <= rhs._fixedPointNumber);
}

bool	Fixed::operator==( Fixed const & rhs ) const {

	return (this->_fixedPointNumber == rhs._fixedPointNumber);
}

bool	Fixed::operator!=( Fixed const & rhs ) const {

	return (this->_fixedPointNumber != rhs._fixedPointNumber);
}

Fixed	Fixed::operator+( Fixed const & rhs ) const {

	Fixed a;

	a._fixedPointNumber = this->_fixedPointNumber + rhs._fixedPointNumber;
	return (a);
}

Fixed	Fixed::operator-( Fixed const & rhs ) const {

	Fixed a;

	a._fixedPointNumber = this->_fixedPointNumber - rhs._fixedPointNumber;
	return (a);
}

Fixed	Fixed::operator*( Fixed const & rhs ) const {

	Fixed	a;

	a._fixedPointNumber = (this->_fixedPointNumber * rhs._fixedPointNumber) >> this->_numFractionalBits;
	return (a);
}

Fixed	Fixed::operator/( Fixed const & rhs ) const {

	Fixed	a;

	a._fixedPointNumber = (this->_fixedPointNumber << this->_numFractionalBits) / rhs._fixedPointNumber;
	return (a);
}

Fixed &	Fixed::operator++( void ) {

	++this->_fixedPointNumber;
	return (*this);
}

Fixed	Fixed::operator++( int ) {

	Fixed	tmp(*this);
	this->_fixedPointNumber++;
	return (tmp);
}

Fixed &	Fixed::operator--( void ) {

	--this->_fixedPointNumber;
	return (*this);
}

Fixed	Fixed::operator--( int ) {

	Fixed	tmp(*this);
	this->_fixedPointNumber--;
	return (tmp);
}

Fixed &	Fixed::min( Fixed & a, Fixed & b ) {

	if (a._fixedPointNumber < b._fixedPointNumber)
		return (a);
	return (b);
}

const Fixed & Fixed::min( const Fixed & a, const Fixed & b ) {

	if (a._fixedPointNumber < b._fixedPointNumber)
		return (a);
	return (b);
}

Fixed &	Fixed::max( Fixed & a, Fixed & b ) {

	if (a._fixedPointNumber > b._fixedPointNumber)
		return (a);
	return (b);
}

const Fixed & Fixed::max( const Fixed & a, const Fixed & b ) {

	if (a._fixedPointNumber > b._fixedPointNumber)
		return (a);
	return (b);
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
