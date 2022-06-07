#include "../includes/iter.hpp"

#define GREEN	"\033[0;32m"
#define RED		"\033[0;31m"
#define RESET	"\033[0m"

int main ( void ) {

	std::cout << std::endl;
	std::cout << GREEN << "Test with array of integers" << RESET << std::endl;
	int foo [5] = { 17, 2, 101, 40, 836 };
	int	fooSize = sizeof(foo) / sizeof(foo[0]);
	iter(foo, fooSize, printElement);

	std::cout << std::endl;
	std::cout << GREEN << "Test with array of strings" << RESET << std::endl;
	std::string bar[4] = {"A", "Few", "Random", "Words"};
	int	barSize = sizeof(bar) / sizeof(bar[0]);
	iter(bar, barSize, printElement);
	std::cout << std::endl;

	return (0);
}
