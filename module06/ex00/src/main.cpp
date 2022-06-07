#include "../includes/DataType.hpp"

#define RED		"\033[0;31m"
#define RESET	"\033[0m"

int	inputValidation( int argc, char **argv ) {

	if (argc != 2)
	{
		std::cout << "invalid amount of arguments" << std::endl;
		std::cout << "USAGE: \"CHAR, INT, FLOAT or DOUBLE\"" << std::endl;
		return (1);
	}
	else if (strlen(argv[1]) == 0)
	{
		std::cout << "invalid argument" << std::endl;
		std::cout << "USAGE: \"CHAR, INT, FLOAT or DOUBLE\"" << std::endl;
		return (1);
	}
	return (0);
}

int main ( int argc, char **argv ) {

	if (inputValidation(argc, argv))
		return (1);

	try {
		DataType type = DataType(argv[1]);
		std::cout << type << std::endl;
	}
	catch (std::exception & e) {
		std::cout << RED << e.what() << RESET <<std::endl;
	}

	return (0);
}
