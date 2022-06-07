#include "../includes/Array.hpp"
#include <iostream>

#define GREEN	"\033[0;32m"
#define RED		"\033[0;31m"
#define RESET	"\033[0m"

#define MAX_VAL 750

int	testIntra( void ) {

	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;
	return 0;

}

int main( void ) {

	std::cout << std::endl;
	std::cout << GREEN << "• main.c by 42 •" << RESET << std::endl << std::endl;
	testIntra();

	std::cout << std::endl;
	std::cout << GREEN << "• Create string array of size two and add two elements •" << RESET << std::endl << std::endl;

	Array<std::string> originalArray(2);

	originalArray[0] = "Hello";
	originalArray[1] = "World";

	std::cout << "Elements originalArray:	" << "[0] " << originalArray[0] << " [1] " << originalArray[1] << std::endl;

	std::cout << std::endl;
	std::cout << GREEN << "• Make copy of originalArray •" << RESET << std::endl << std::endl;

	Array<std::string> copyArray(originalArray);

	std::cout << "Elements copyArray:	" << "[0] " << copyArray[0] << " [1] " << copyArray[1] << std::endl;

	std::cout << std::endl;
	std::cout << GREEN << "• Change element of copyArray to proof it's a deep copy •" << RESET << std::endl << std::endl;

	copyArray[1] = "People";

	std::cout << "Elements originalArray:	" << "[0] " << originalArray[0] << " [1] " << originalArray[1] << std::endl;
	std::cout << "Elements copyArray:	" << "[0] " << copyArray[0] << " [1] " << copyArray[1] << std::endl;

	std::cout << std::endl;
	std::cout << GREEN << "• Assign int array of size 5 to int array of size 2 •" << RESET << std::endl << std::endl;

	try {
		Array<int> bigArray(5);
		for (int i = 0; i < 5; i++)
			bigArray[i] = i;
		Array<int> smallArray(2);
		smallArray = bigArray;
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << GREEN << "• Assign element to empty array •" << RESET << std::endl << std::endl;

	try {
		Array<int> empty = Array<int>();
		empty[0] = 5;
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << GREEN << "• Create char array just for fun •" << RESET << std::endl << std::endl;

	Array<char> charArray(5);
	std::string codam = "codam";
	for (int i = 0; i < 5; i++) {
		charArray[i] = codam[i];
		std::cout << "[" << i << "] " << charArray[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Size charArray = " << charArray.size() << std::endl;
	std::cout << std::endl;

	return (0);
}
