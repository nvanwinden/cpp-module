#include "../includes/classes.hpp"
#include <iostream>

Base * generate(void) {

	Base* type;
	int	random = std::rand() % 3;
	switch (random) {
		case 0:
			type = new A();
			std::cout << "Created type A" << std::endl;
			return (type);
		case 1:
			type = new B();
			std::cout << "Created type B" << std::endl;
			return (type);
		case 2:
			type = new C();
			std::cout << "Created type C" << std::endl;
			return (type);
		default:
			NULL;
	}
	return (NULL);
}

void identify(Base* p) {

	A* a = dynamic_cast<A*>(p);
	if (a != NULL)
	{
		std::cout << "A identified" << std::endl;
		return ;
	}
	B* b = dynamic_cast<B*>(p);
	if (b != NULL)
	{
		std::cout << "B identified" << std::endl;
		return ;
	}
	C* c = dynamic_cast<C*>(p);
	if (c != NULL)
	{
		std::cout << "C identified" << std::endl;		
		return ;
	}
	return ;
}

void identify(Base& p) {

	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A identified" << std::endl;
		return;
	}
	catch (std::exception & e) {}
	try {
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B identified" << std::endl;
		return;
	}
	catch (std::exception & e) {}
	try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C identified" << std::endl;
		return;
	}
	catch (std::exception & e) {}
	return ;
}

int main ( void ) {

	srand(time(0));

	Base *ptr = generate();

	identify(ptr);

	identify(*ptr);

	delete ptr;

	return (0);
}
