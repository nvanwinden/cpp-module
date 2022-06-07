#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>

/* constructors and destructor */

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("ShrubberyCreationForm", 137, 145) {

	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target )
	: AForm("ShrubberyCreationForm", target, 137, 145) {

	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src )
	: AForm(src.getName(), src.getTarget(), 137, 145) {

	*this = src;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {

	return ;
}

/* copy assignment operator */

ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs ) {

	(void)rhs;
	return (*this);
}

void	ShrubberyCreationForm::action( void ) const {

	std::ofstream	newFile;
	std::string		tree[100] = {

		"      /\\      ",
		"     /\\*\\     ",
		"    /\\O\\*\\    ",
		"   /*/\\/\\/\\   ",
		"  /\\O\\/\\*\\/\\  ",
		" /\\*\\/\\*\\/\\/\\ ",
		"/\\O\\/\\/*/\\/O/\\",
		"      ||      ",
		"      ||      ",
		"      ||      "
	};

	newFile.open(this->getTarget() + "_shrubbery");
	if (!newFile)
		throw(this->getTarget() + "_shrubbery failed to open");
	for (int i = 0; i < 5; i++)
	{
		for (int i = 0; i < 10; i++)
			newFile << tree[i] << "\n";
	}
	newFile.close();
	if (!newFile)
		throw(this->getTarget() + "_shrubbery failed to close");

	return ;
}
