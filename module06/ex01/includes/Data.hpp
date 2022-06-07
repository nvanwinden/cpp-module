#ifndef DATA_HPP
# define DATA_HPP

#include <string>

class Data {

public:

	Data( void );
	Data ( std::string name, int age );
	Data( Data const & src );
	~Data( void );

	std::string		getName( void ) const ;
	int				getAge( void ) const ;

	Data &	operator=( Data const & rhs );

private:

	std::string	_name;
	int			_age;

};

uintptr_t	serialize( Data* ptr );
Data *		deserialize( uintptr_t raw );

#endif
