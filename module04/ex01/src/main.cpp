#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int main ( void ) {

	int	n = 6;

	std::cout << std::endl << GREEN << "• Create and array of " << n << " animal objects •" << RESET << std::endl << std::endl;
	const Animal *animals[n];

	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}

	std::cout << std::endl << GREEN << "• To proof half of the animals are dog objects and the other half are cat objects •" << RESET << std::endl << std::endl;

	for (int i = 0; i < n; i++)
	{
		animals[i]->makeSound();
		std::cout << " I am a " << animals[i]->getType() << std::endl << std::endl;
	}

	std::cout << GREEN << "• Delete every animal •" << RESET << std::endl << std::endl;

	for (int i = 0; i < n; i++)
		delete animals[i];

	std::cout << std::endl << GREEN << "• To proof that the copies are deep copies we create a new cat class •" << RESET << std::endl << std::endl;
	
	const Cat ziggy = Cat();

	std::cout << std::endl << GREEN << "• And we put some thoughts into the cat's brain •" << RESET << std::endl << std::endl;

	ziggy.getBrain()->_ideas[0] = "Taco cat backwards is taco cat";
	ziggy.getBrain()->_ideas[1] = "It's so beautiful, I must kill it";
	ziggy.getBrain()->_ideas[2] = "I won't smile, you can't make me";

	std::cout << ziggy.getBrain()->_ideas[0] << std::endl;
	std::cout << ziggy.getBrain()->_ideas[1] << std::endl;
	std::cout << ziggy.getBrain()->_ideas[2] << std::endl;

	std::cout << std::endl << GREEN << "• Now we make a second cat class, the thoughts are copied to this class •" << RESET << std::endl << std::endl;

	const Cat second = ziggy;

	std::cout << std::endl;
	std::cout << second.getBrain()->_ideas[0] << std::endl;
	std::cout << second.getBrain()->_ideas[1] << std::endl;
	std::cout << second.getBrain()->_ideas[2] << std::endl << std::endl;

	std::cout << GREEN << "• We now change ideas[0] of the second Cat and print their thoughts to proof both classes point to a unique block of memory •" << RESET << std::endl << std::endl;

	second.getBrain()->_ideas[0] = "This is my new thought";

	std::cout << "Ideas ziggy:" << std::endl;
	std::cout << ziggy.getBrain()->_ideas[0] << std::endl;
	std::cout << ziggy.getBrain()->_ideas[1] << std::endl;
	std::cout << ziggy.getBrain()->_ideas[2] << std::endl;
	std::cout << std::endl;
	std::cout << "Ideas copy:" << std::endl;
	std::cout << second.getBrain()->_ideas[0] << std::endl;
	std::cout << second.getBrain()->_ideas[1] << std::endl;
	std::cout << second.getBrain()->_ideas[2] << std::endl << std::endl;

	return 0;
}
