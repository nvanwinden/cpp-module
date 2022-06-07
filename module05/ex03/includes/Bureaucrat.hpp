#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#define GREEN	"\033[0;32m"
#define RED		"\033[0;31m"
#define RESET	"\033[0m"

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class AForm;

class Bureaucrat {

public:

	Bureaucrat( void );
	Bureaucrat( std::string const name, unsigned int grade );
	Bureaucrat( Bureaucrat const & src );
	~Bureaucrat( void );

	std::string const	getName( void ) const;
	unsigned int		getGrade( void ) const;

	void				incrementGrade( void );
	void				decrementGrade( void );
	void				signForm( AForm & form );
	void				executeForm( AForm const & form );

	class GradeTooHighException : public std::exception {

	public:

		const char *	what() const throw();
	};

	class GradeTooLowException : public std::exception {

	public:

		const char * 	what() const throw();
	};

	Bureaucrat &		operator=( Bureaucrat const & rhs );

private:

	std::string	const	_name;
	unsigned int		_grade;

};

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs );

#endif
