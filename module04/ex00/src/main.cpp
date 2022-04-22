#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongCat.hpp"

int main ( void ) {

	std::cout << std::endl;

	const Animal		*meta = new Animal();
	const Animal		*j = new Dog();
	const Animal		*i = new Cat();

	std::cout << std::endl;
	std::cout << meta->getType() << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() <<  std::endl << std::endl;

	meta->makeSound();
	i->makeSound();
	j->makeSound();
	std::cout << std::endl;

	const WrongAnimal	*k = new WrongCat();

	std::cout << std::endl;
	k->makeSound();
	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;
	delete k;

	return (0);
}
