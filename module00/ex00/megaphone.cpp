/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/28 13:32:49 by nvan-win      #+#    #+#                 */
/*   Updated: 2022/03/10 08:39:25 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	to_upper(int c) {

	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

void	print_arg(char *arg) {

	int	i;

	i = 0;
	while (arg[i])
	{
		arg[i] = to_upper(arg[i]);
		std::cout << arg[i];
		i++;
	}
}

int main (int argc, char **argv) {

	int	i;

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (i = 1; i < argc; i++)
			print_arg(argv[i]);
	}
	std::cout << std::endl;
}
