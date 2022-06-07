#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
#include <iostream>

template < typename T >
class Array {

public:

	/* constructors and destructor */

	Array<T>( void ) : _size(0) {

		_array = new T[_size];
	};

	Array<T>( unsigned int n ) : _size(n) {
		_array = new T[n];
	};

	~Array<T>( void ) {

		delete [] this->_array;
	};

	Array<T>( Array<T> const & src ) {

		this->_size = src._size;
		this->_array = new T[this->_size];
		*this = src;
	};

	/* copy assignment operator */

	Array<T> &	operator=( Array<T> const & rhs ) {

		if (this->_size != rhs.size())
			throw(ArraySizeIncompatibleException());
		for (unsigned int i = 0; i < rhs.size(); i++)
			this->_array[i] = rhs._array[i];
		return (*this);
	};

	/* subscript operator */

	T &	operator[]( unsigned int i ) {

		if (i < 0 || i >= this->_size)
			throw(OutOfBounceException());
		return (_array[i]);
	};

	/* exceptions */

	class OutOfBounceException : public std::exception {

	public:

		const char *	what() const throw() { return("Array<T>::OutOfBounceException"); };
	};

	class ArraySizeIncompatibleException : public std::exception {

	public:

		const char *	what() const throw() { return("Array<T>::ArraySizeIncompatibleException"); };
	};

	/* Member function */

	unsigned int size( void ) const { return(_size); };

private:

	T*					_array;
	unsigned int		_size;

};

#endif
