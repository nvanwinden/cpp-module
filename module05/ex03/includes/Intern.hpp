#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern {

public:

	enum Forms {
		SHRUBBERY,
		ROBOTOMY,
		PRESIDENTIAL
	};

	Intern( void );
	Intern( Intern const & src );
	~Intern( void );

	AForm *		makeForm( std::string form, std::string target );

	class FormDoesNotExistException : public std::exception {

	public:

		const char*	what() const throw();
	};

	Intern &	operator=( Intern const & rhs );

private:

};

#endif
