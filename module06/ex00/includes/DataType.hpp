#ifndef DATA_TYPE_HPP
# define DATA_TYPE_HPP

#include <iostream>
#include <exception>

class DataType {

public:

	enum Types {
		CHAR,
		INT,
		FLOAT,
		DOUBLE
	};

	DataType( std::string input );
	DataType( DataType const & src );
	~DataType( void );

	std::string const getInput( void ) const;
	char		getChar( void ) const;
	int			getInt( void ) const;
	double		getDouble( void ) const;
	float		getFloat( void ) const;
	
	std::string	printChar( void ) const;
	void		printInt( void ) const;
	void		printFloat( void ) const;
	void		printDouble( void ) const;

	DataType &	operator=( DataType const & rhs );

	class UnknownTypeException : public std::exception {

	public:

		const char*	what() const throw();
	};

	class IntOverflowException : public std::exception {

	public:

		const char*	what() const throw();
	};

private:

	DataType( void );

	bool				_impossible[4];
	std::string const	_input;
	char				_c;
	int					_n;
	double				_d;
	float				_f;

	bool				isChar( void );
	bool				isInt( void );
	bool				isFloat( void );
	bool				isDouble( void );
	bool				isPseudoFloat( void );
	bool				isPseudoDouble( void );

	void				charConv( void );
	void				intConv( void );
	void				floatConv( void );
	void				doubleConv( void );

};

std::ostream &	operator<<( std::ostream & o, DataType const & rhs );

#endif
