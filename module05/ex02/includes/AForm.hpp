#ifndef AFORM_HPP
# define AFORM_HPP

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

class AForm {

public:

	AForm( void );
	AForm( std::string const name, unsigned int exec, unsigned int sign );
	AForm( std::string const name, std::string const target, unsigned int exec, unsigned int sign );
	AForm( AForm const & src );
	virtual ~AForm( void );

	std::string const	getName( void ) const;
	std::string const	getTarget( void ) const;
	unsigned int		getExec( void ) const;
	unsigned int		getSign( void ) const;
	bool				getSigned( void ) const;

	void				beSigned( Bureaucrat & bureaucrat );
	void				execute( Bureaucrat const & executor ) const;

	class GradeTooHighException : public std::exception {

	public:

		const char*	what() const throw();
	};

	class GradeTooLowException : public std::exception {

	public:

		const char*	what() const throw();
	};

	class FormNotSignedException : public std::exception {

	public:

		const char*	what() const throw();
	};	

	AForm &			operator=( AForm const & rhs );

private:

	std::string const	_name;
	std::string const	_target;
	unsigned int const	_exec;
	unsigned int const	_sign;
	bool				_signed;

	virtual	void		action( void ) const = 0;

};

std::ostream &	operator<<( std::ostream & o, AForm const & rhs );

#endif
