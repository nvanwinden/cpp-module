#ifndef FORM_HPP
# define FORM_HPP

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

class Form {

public:

	Form( void );
	Form( std::string const name, unsigned int exec, unsigned int sign );
	Form( Form const & src );
	~Form( void );

	std::string const	getName( void ) const;
	unsigned int		getExec( void ) const;
	unsigned int		getSign( void ) const;
	bool				getSigned( void ) const;

	void				beSigned( Bureaucrat & bureaucrat );

	class GradeTooHighException : public std::exception {

	public:

		const char*	what() const throw();
	};

	class GradeTooLowException : public std::exception {

	public:

		const char*	what() const throw();
	};

	Form &			operator=( Form const & rhs );

private:

	std::string const	_name;
	unsigned int const	_exec;
	unsigned int const	_sign;
	bool				_signed;

};

std::ostream &	operator<<( std::ostream & o, Form const & rhs );

#endif
