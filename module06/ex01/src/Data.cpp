#include "../includes/Data.hpp"

/* constructors and destructor */

Data::Data( void ) {} ;

Data::Data( std::string name, int age ) : _name(name), _age(age) {} ;

Data::Data( Data const & src ) {

	*this = src;
}

Data::~Data() {} ;

/* copy assignment operator */

Data &	Data::operator=( Data const & rhs ) {

	this->_name = rhs.getName();
	this->_age = rhs.getAge();
 	return (*this);
}

/* getters */

std::string	Data::getName( void ) const {

	return (this->_name);
}

int			Data::getAge( void ) const {

	return (this->_age);
}

/* functions */

uintptr_t	serialize( Data* ptr ) {

	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *		deserialize( uintptr_t raw ) {

	return (reinterpret_cast<Data *>(raw));
}
