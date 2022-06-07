#include "../includes/Data.hpp"
#include <iostream>

int main ( void ) {

	std::cout << "Original type: Data *" << std::endl << std::endl;

	Data*	member = new Data("John", 42);

	std::cout << "Name member: " << member->getName() << std::endl;
	std::cout << "Age member: " << member->getAge() << std::endl << std::endl;

	std::cout << "Address of original type in memory: " << member << std::endl << std::endl;

	std::cout << "Serialize Data * to an uintptr_t data type " << std::endl;
	uintptr_t uIntPtr = serialize(member);
	std::cout << "The data * address is stored as an unsigned integer: " << uIntPtr << std::endl << std::endl;

	std::cout << "Deserialize uintptr_t back to the address of Data * member: ";
	Data *data_deserialize = deserialize(uIntPtr);
	std::cout << data_deserialize << std::endl << std::endl;

	std::cout << "Name member: " << member->getName() << std::endl;
	std::cout << "Age member: " << member->getAge() << std::endl << std::endl;

	delete member;

	return (0);
}
