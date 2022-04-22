/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 16:38:40 by nvan-win      #+#    #+#                 */
/*   Updated: 2022/03/18 10:18:09 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int main (int argc, char **argv) {

	Harl harl;

	if (argc == 2)
		harl.complain(argv[1]);
	else
		std::cout << "Error: invalid amount of arguments, program takes log level as parameter" << std::endl;
	return (0);
}
