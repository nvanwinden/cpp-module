#include "../includes/MutantStack.hpp"

#define GREEN	"\033[0;32m"
#define RED		"\033[0;31m"
#define RESET	"\033[0m"

#include <iostream>
#include <list>

void	testSubject() {

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	std::cout << *it << std::endl;
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	 while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

}

void	testSubjectCmp() {

	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	// //[...]
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::cout << *it << std::endl;
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
		}
	std::list<int> s(mstack);

}

void	revTest() {

	MutantStack<int> revTest;

	revTest.push(1);
	revTest.push(2);
	revTest.push(3);
	revTest.push(4);
	revTest.push(5);

	MutantStack<int>::const_reverse_iterator it;

	for (it = revTest.crbegin(); it != revTest.crend(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

}

void	revTestCmp() {

	std::list<int> revTestCmp;

	revTestCmp.push_back(1);
	revTestCmp.push_back(2);
	revTestCmp.push_back(3);
	revTestCmp.push_back(4);
	revTestCmp.push_back(5);

	std::list<int>::const_reverse_iterator it;
	
 	for (it = revTestCmp.crbegin(); it != revTestCmp.crend(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

}

void	copyTest() {

	MutantStack<int> copyTest;

	copyTest.push(5);
	copyTest.push(33);
	copyTest.push(42);

	MutantStack<int> makeCopy(copyTest);

	MutantStack<int>::const_iterator it;

	for (it = copyTest.cbegin(); it != copyTest.cend(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	MutantStack<int>::const_iterator itCopy;

	for (itCopy = makeCopy.cbegin(); itCopy != makeCopy.cend(); itCopy++) {
		std::cout << *itCopy << " ";
	}

	std::cout << std::endl;

	return ;
}

int main ( void ) {

	std::cout << std::endl;
	std::cout << GREEN << "• Test provided by subject •" << RESET << std::endl << std::endl;
	testSubject();
	std::cout << std::endl;
	std::cout << GREEN << "• Compare output with another container •" << RESET << std::endl << std::endl;
	testSubjectCmp();
	std::cout << std::endl;
	std::cout << GREEN << "• Test reverse iterator •" << RESET << std::endl << std::endl;
	revTest();
	std::cout << std::endl;
	std::cout << GREEN << "• Compare output with another container •" << RESET << std::endl << std::endl;
	revTestCmp();
	std::cout << std::endl;
	std::cout << GREEN << "• Test copy •" << RESET << std::endl << std::endl;
	copyTest();
	std::cout << std::endl;
	return 0;
}
