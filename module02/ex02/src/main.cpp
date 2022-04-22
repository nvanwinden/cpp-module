/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 11:37:56 by nvan-win      #+#    #+#                 */
/*   Updated: 2022/04/12 11:38:18 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

int main ( void ) {

	std::cout << std::endl << GREEN << "== Example subject ==" << RESET << std::endl << std::endl;

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl << std::endl;

	std::cout << GREEN << "== Comparison operator overloading ==" << RESET << std::endl << std::endl;

	Fixed	c(42);
	Fixed	d(20);
	Fixed	e(42);

	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << std::endl;

	std::cout << GREEN << "Greater Than" << RESET << std::endl;
	std::cout << "c > d: " << (c > d) << std::endl;
	std::cout << "d > c: " << (d > c) << std::endl;
	std::cout << "c > e: " << (c > e) << std::endl;

	std::cout << GREEN << "Less Than" << RESET << std::endl;
	std::cout << "c < d: " << (c < d) << std::endl;
	std::cout << "d < c: " << (d < c) << std::endl;
	std::cout << "c < e: " << (c < e) << std::endl;

	std::cout << GREEN << "Greater Than or Equal To" << RESET << std::endl;
	std::cout << "c >= d: " << (c >= d) << std::endl;
	std::cout << "d >= c: " << (d >= c) << std::endl;
	std::cout << "c >= e: " << (c >= e) << std::endl;

	std::cout << GREEN << "Less Than or Equal To" << RESET << std::endl;
	std::cout << "c <= d: " << (c <= d) << std::endl;
	std::cout << "d <= c: " << (d <= c) << std::endl;
	std::cout << "c <= e: " << (c <= e) << std::endl;

	std::cout << GREEN << "Equals" << RESET << std::endl;
	std::cout << "c == d: " << (c == d) << std::endl;
	std::cout << "d == c: " << (d == c) << std::endl;
	std::cout << "c == e: " << (c == e) << std::endl;

	std::cout << GREEN << "Not Equal To" << RESET << std::endl;
	std::cout << "c != d: " << (c != d) << std::endl;
	std::cout << "d != c: " << (d != c) << std::endl;
	std::cout << "c != e: " << (c != e) << std::endl;
	std::cout << std::endl;

	std::cout << GREEN << "== Arithmetic operator overloading ==" << RESET << std::endl << std::endl;

	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << std::endl;

	std::cout << GREEN << "Addition" << RESET << std::endl;
	Fixed f = c + d;
	std::cout << "c + d: " << f << std::endl;
	std::cout << GREEN << "Subtraction" << RESET << std::endl;
	Fixed g = c - d;
	std::cout << "c - d: " << g << std::endl;
	std::cout << GREEN << "Multiplication" << RESET << std::endl;
	Fixed h = Fixed(5) * Fixed(5);
	std::cout << "Fixed(5) * Fixed(5): " << h << std::endl;
	std::cout << GREEN << "Division" << RESET << std::endl;
	Fixed i = Fixed(25) / Fixed(5);
	std::cout << "Fixed(25) / Fixed(5): " << i << std::endl;
	std::cout << std::endl;

	std::cout << GREEN << "== Min/Max overload functions ==" << RESET << std::endl << std::endl;

	Fixed j(5.42f);
	Fixed k(4.22f);
	Fixed const l(118);
	Fixed const	m(119);

	std::cout << "j = " << j << std::endl;
	std::cout << "k = " << k << std::endl;
	std::cout << "l = " << l << std::endl;
	std::cout << "m = " << m << std::endl;
	std::cout << std::endl;

	std::cout << "smallest value (j,k): " << Fixed::min(j, k) << std::endl;
	std::cout << "smallest value (l,m): " << Fixed::min(l, m) << std::endl;
	std::cout << "greatest value (j,k): " << Fixed::max(j, k) << std::endl;
	std::cout << "greatest value (l,m): " << Fixed::max(l, m) << std::endl;
	std::cout << std::endl;

	return (0);
}
