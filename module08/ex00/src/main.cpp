#include "../includes/easyfind.hpp"

#define GREEN	"\033[0;32m"
#define RED		"\033[0;31m"
#define RESET	"\033[0m"

#include <iostream>
#include <list>
#include <vector>
#include <array>
#include <deque>
#include <forward_list>

void	print(int const & value) {

	std::cout << value << std::endl;
}

void	testForwardList() {

	std::cout << GREEN << "• Create a forward_list<int> •" << RESET << std::endl << std::endl;

	std::forward_list<int> foo;
	int n = 5;

	foo.push_front(5);
	foo.push_front(4);
	foo.push_front(3);
	foo.push_front(2);
	foo.push_front(1);

	std::for_each(std::begin(foo), std::end(foo), print);

	std::cout << std::endl;
	std::cout << GREEN << "• Find first occurence of " << n <<  " in forward_list<int> •" << RESET << std::endl << std::endl;

	try {
		std::forward_list<int>::const_iterator res = easyfind(foo, n);
		std::forward_list<int>::iterator it;
		int pos = 0;
		for (it = foo.begin(); it != foo.end(); it++) {
			if (*res == *it)
				break;
			pos++;
		}
		std::cout << "Element found! Memory address iterator [" << &(*res) << "] and memory address container [" << &(*it) << "]" << std::endl;
	}
	catch (const std::exception & e) {
		std::cout << RED << e.what() << " element not found in container" << RESET << std::endl;
	}
	return ;
}

void	testDeque() {

	std::cout << GREEN << "• Create a deque<int> •" << RESET << std::endl << std::endl;

	std::vector<int> foo;
	int n = 5;

	foo.push_back(1);
	foo.push_back(2);
	foo.push_back(3);
	foo.push_back(4);
	foo.push_back(5);

	std::for_each(std::begin(foo), std::end(foo), print);

	std::cout << std::endl;
	std::cout << GREEN << "• Find first occurence of " << n <<  " in deque<int> •" << RESET << std::endl << std::endl;

	try {
		std::vector<int>::const_iterator it = easyfind(foo, n);
		std::cout << "Element found! Memory address iterator [" << &(*it) << "] and memory address container [" << &foo[4] << "]" << std::endl;
	}
	catch (const std::exception & e) {
		std::cout << RED << e.what() << " element not found in container" << RESET << std::endl;
	}
}

void	testList() {

	std::cout << GREEN << "• Create a list<int> •" << RESET << std::endl << std::endl;

	std::list<int> foo;

	for (int i = 0; i < 15; i++) {
		foo.push_front(std::rand() % 50);
	}

	std::for_each(std::begin(foo), std::end(foo), print);

	int n = std::rand() % 50;

	std::cout << std::endl;
	std::cout << GREEN << "• Find first occurence of " << n <<  " in list<int> •" << RESET << std::endl << std::endl;

	try {
		std::list<int>::const_iterator res = easyfind(foo, n);
		std::list<int>::iterator it;
		int pos = 0;
		for (it = foo.begin(); it != foo.end(); it++) {
			if (*res == *it)
				break;
			pos++;
		}
		std::cout << "Element found! Memory address iterator [" << &(*res) << "] and memory address container [" << &(*it) << "]" << std::endl;
	}
	catch (const std::exception & e) {
		std::cout << RED << e.what() << " element not found in container" << RESET << std::endl;
	}
	return ;
}

void	testArray() {

	std::cout << GREEN << "• Create a array<int> •" << RESET << std::endl << std::endl;
	int n = 66;

	std::array<int,11> foo = {98, 0, 123, 3, 66, 12, 5, 66, 7, 8, 9};

	std::for_each(std::begin(foo), std::end(foo), print);

	std::cout << std::endl;
	std::cout << GREEN << "• Find first occurence of " << n <<  " in array<int> •" << RESET << std::endl << std::endl;

	try {
		std::array<int, 11>::const_iterator it = easyfind(foo, n);
		std::cout << "Element found! Memory address iterator [" << &(*it) << "] and memory address array [" << &foo[4] << "]" << std::endl;
	}
	catch (const std::exception & e) {
		std::cout << RED << e.what() << " element not found in container" << RESET << std::endl;
	}

	std::cout << std::endl;
	std::cout << GREEN << "• Test with element that doesn't exist in array<int> •" << RESET << std::endl;
	std::cout << std::endl;
	n = 42;

	try {
		std::array<int, 11>::const_iterator it = easyfind(foo, n);
		std::cout << "Element found! Memory address iterator [" << &(*it) << "] and memory address container [" << &foo[4] << "]" << std::endl;
	}
	catch (const std::exception & e) {
		std::cout << RED << e.what() << " element not found in container" << RESET << std::endl;
	}
	std::cout << std::endl;
	return ;
}

void	testVector() {

	std::cout << GREEN << "• Create a vector<int> •" << RESET << std::endl << std::endl;

	std::vector<int> foo;
	int n = 42;

	foo.push_back(0);
	foo.push_back(42);
	foo.push_back(13);
	foo.push_back(88);
	foo.push_back(123);
	foo.push_back(42);

	std::for_each(std::begin(foo), std::end(foo), print);

	std::cout << std::endl;
	std::cout << GREEN << "• Find first occurence of " << n <<  " in vector<int> •" << RESET << std::endl << std::endl;

	try {
		std::vector<int>::const_iterator it = easyfind(foo, n);
		std::cout << "Element found! Memory address iterator [" << &(*it) << "] and memory address container [" << &foo[1] << "]" << std::endl;
	}
	catch (const std::exception & e) {
		std::cout << RED << e.what() << " element not found in container" << RESET << std::endl;
	}

	std::cout << std::endl;
	std::cout << GREEN << "• Remove " << n << " from vector<int> •" << RESET << std::endl << std::endl;

	foo.erase(std::remove(foo.begin(), foo.end(), 42), foo.end());

	std::for_each(std::begin(foo), std::end(foo), print);

	std::cout << std::endl;
	std::cout << GREEN << "• Find first occurence of " << n << " in vector<int> •" << RESET << std::endl << std::endl;

	try {
		std::vector<int>::const_iterator it = easyfind(foo, n);
		std::cout << "Element found! Memory address iterator [" << &(*it) << "] and memory address container [" << &foo[1] << "]" << std::endl;
	}
	catch (const std::exception & e) {
		std::cout << RED << e.what() << " element not found in container" << RESET << std::endl;
	}

	std::cout << std::endl;
	return ;
}

int main ( void ) {

	srand(time(0));
	std::cout << std::endl;
	testVector();
	std::cout << std::endl;
	testArray();
	std::cout << std::endl;
	testList();
	std::cout << std::endl;
	testDeque();
	std::cout << std::endl;
	testForwardList();
	std::cout << std::endl;
	return (0);
}
