/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 15:29:14 by nvan-win      #+#    #+#                 */
/*   Updated: 2022/04/06 09:02:54 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main ( void ) {

	std::string	str = "HI THIS IS BRAIN";
	std::string	*strPtr = &str;
	std::string &strRef = str;

	std::cout << "memory address of str: " << &str << std::endl;
	std::cout << "memory address of strPtr: " << strPtr << std::endl;
	std::cout << "memory address of strRef: " << &strRef << std::endl << std::endl ;

	std::cout << "value of str: " << str << std::endl;
	std::cout << "value of strPtr: " << *strPtr << std::endl;
	std::cout << "value of strRef: " << strRef << std::endl;
}
