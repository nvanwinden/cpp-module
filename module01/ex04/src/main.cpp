/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 16:11:02 by nvan-win      #+#    #+#                 */
/*   Updated: 2022/03/18 11:51:58 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Replace.hpp"

int	error_msg() {

	std::cout << "invalid amount of arguments" << std::endl;
	std::cout << "parameters: \"file\" \"s1\" \"s2\"" << std::endl;
	return (1);
}

int	replacer(std::string fileName, std::string s1, std::string s2)
{
	Replace replacer(fileName, s1, s2);

	if (replacer.error == 1)
		return (1);
	return (0);
}

int main (int argc, char **argv) {

	if (argc != 4)
		return (error_msg());
	if (replacer(argv[1], argv[2], argv[3]))
		return (1);
	return (0);
}
