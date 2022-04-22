/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 08:42:45 by nvan-win      #+#    #+#                 */
/*   Updated: 2022/03/10 11:25:03 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"
	
int main (void) {

	Phonebook	phonebook;
	std::string	input;

	while (input != "EXIT")
	{
		phonebook.prompt();
		std::getline(std::cin, input);
		if (std::cin.good() != 1)
			return (0);
		else if (input.find('\t') != std::string::npos)
			std::cout << RED << "tabs are not valid input" << RESET << std::endl;
		else if (input.empty())
			std::cout << RED << "input field can not be empty" << RESET << std::endl << std::endl;
		else if (input != "ADD" && input != "SEARCH" && input != "EXIT")
			std::cout << RED << input << " is not a valid command" << RESET << std::endl;
		else if (input == "ADD")
		{
			if (phonebook.addContact())
				return (0);
		}
		else if (input == "SEARCH")
			if (phonebook.searchContact())
				return (0);
	}
	return (0);
}
