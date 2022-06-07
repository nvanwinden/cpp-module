#include "../includes/DataType.hpp"
#include <iomanip>
#include <cmath>

/* constructors and destructor */

DataType::DataType( void ) {};

DataType::DataType( std::string input ) : _input(input) {

	for (int i = 0; i < 4; i++) {
		this->_impossible[i] = false;
	}

	bool (DataType::*type[]) () = { &DataType::isChar, &DataType::isInt, &DataType::isFloat, &DataType::isDouble };

	int i = 0;
	while (i < 4) {

		if ((this->*type[i])())
			break;
		i++;
	}
	switch (i) {
		case CHAR:
			charConv();
			break;
		case INT:
			intConv();
			break;
		case FLOAT:
			floatConv();
			break;
		case DOUBLE:
			doubleConv();
			break;
		default:
			throw(DataType::UnknownTypeException());
	}
	return ;
};

DataType::DataType( DataType const & src ) : _input(src.getInput()) { *this = src; };

DataType::~DataType( void ) {};

/* copy assignment operator */

DataType & DataType::operator=( DataType const & rhs ) {

	for (int i = 0; i < 4; i++) {
		this->_impossible[i] = rhs._impossible[i];
	}
	this->_c = rhs.getChar();
	this->_n = rhs.getInt();
	this->_d = rhs.getDouble();
	this->_f = rhs.getFloat();
 	return (*this);
}

/* public member functions */

std::string	DataType::printChar( void ) const {

	std::string singleQuotes = "''";
	if (this->_impossible[CHAR])
		return ("impossible");
	else if (std::isprint(this->_c))
		return (singleQuotes.insert(1, 1, this->_c));
	else
		return ("Non displayable");
}

void		DataType::printInt( void ) const {

	if (this->_impossible[INT])
		std::cout << "impossible" << std::endl;
	else
		std::cout << this->_n << std::endl;
}

void		DataType::printDouble( void ) const {

	if (this->_d == INFINITY && this->_d > 0)
		std::cout << "+" << this->_d << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << this->_d << std::endl;
}

void		DataType::printFloat( void ) const {

	if (this->_f == INFINITY && this->_f > 0)
		std::cout << "+" << std::fixed << std::setprecision(1) << this->_f << "f" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << this->_f << "f" << std::endl;	
}

/* getters */

std::string const   DataType::getInput( void ) const {

	return (this->_input);
}

char		DataType::getChar( void ) const {

	return (this->_c);
}

int			DataType::getInt( void ) const {

	return (this->_n);
}

double		DataType::getDouble( void ) const {

	return (this->_d);
}

float		DataType::getFloat( void ) const {

	return (this->_f);
}

/* exceptions */

const char *	DataType::UnknownTypeException::what() const throw() {

	return ("DataType::UnknownTypeException");
}

const char *	DataType::IntOverflowException::what() const throw() {

	return ("DataType::IntOverflowException");
}

/* private member functions */

bool	DataType::isChar( void ) {

	if (_input.length() == 1 && !std::isdigit(_input[0]))
		return (true);
	return (false);
}

bool	DataType::isInt( void ) {

	for (size_t i = 0; i < this->_input.length(); i++ ) {

		if ((this->_input[i] == '-' || this->_input[i] == '+') && i == 0)
			continue;
		else if (!std::isdigit(this->_input[i]))
			return (false);
	}

	double d = strtod(this->_input.c_str(), NULL);
	if (d < INT_MIN || d > INT_MAX) {
		throw(IntOverflowException());
	}

	return (true);
}

bool	DataType::isFloat( void ) {

	bool point = false;

	if (isPseudoFloat())
		return (true);
	if (this->_input[this->_input.length() - 1] != 'f' &&
		this->_input[this->_input.length() - 1] != 'F')
		return (false);
	for (size_t i = 0; i < this->_input.length() - 1; i++) {
		if ((this->_input[i] == '-' || this->_input[i] == '+') && i == 0)
			continue;
		else if (!std::isdigit(this->_input[i]))
		{
			if (this->_input[i] == '.' && !point)
				point = true;
			else
				return (false);
		}
	}
	if (!point)
		return (false);
	return (true);
}

bool	DataType::isDouble( void ) {

	bool point = false;

	if (isPseudoDouble())
	 	return (true);
	for (size_t i = 0; i < this->_input.length(); i++) {
		if ((this->_input[i] == '-' || this->_input[i] == '+') && i == 0)
			continue;
		else if (!std::isdigit(this->_input[i]))
		{
			if (this->_input[i] == '.' && !point)
				point = true;
			else
				return (false);
		}
	}
	return (true);
}

bool	DataType::isPseudoFloat( void ) {

	if (this->_input == "-inff" || this->_input == "+inff" || this->_input == "nanf")
	{
		this->_impossible[CHAR] = true;
		this->_impossible[INT] = true;
		return (true);
	}
	return (false);
}

bool	DataType::isPseudoDouble( void ) {

	if (this->_input == "-inf" || this->_input == "+inf" || this->_input == "nan")
	{
		this->_impossible[CHAR] = true;
		this->_impossible[INT] = true;
		return (true);
	}
	return (false);
}

void	DataType::charConv( void ) {

	this->_c = _input[0];

	this->_n = static_cast<int>(this->_c);
	this->_f = static_cast<float>(this->_c);
	this->_d = static_cast<double>(this->_c);
	return ;
}

void	DataType::intConv( void ) {

	this->_n = static_cast<int>(std::strtol(this->_input.c_str(), NULL, 10));

	if (this->_n < 0 || this->_n > 255)
		this->_impossible[CHAR] = true;
	else
		this->_c = static_cast<char>(this->_n);
	this->_f = static_cast<float>(this->_n);
	this->_d = static_cast<double>(this->_n);
	return ;
}

void	DataType::floatConv( void ) {

	std::string removeF = this->_input.substr(0, this->_input.length() - 1);
	this->_f = static_cast<float>(std::strtod(removeF.c_str(), NULL));

	this->_d = static_cast<double>(this->_f);
	if (static_cast<int>(this->_d) < 0 || static_cast<int>(this->_d) > 255)
		this->_impossible[CHAR] = true;
	else
		this->_c = static_cast<char>(this->_f);
	if (this->_d < INT_MIN || this->_d > INT_MAX)
		this->_impossible[INT] = true;
	else
		this->_n = static_cast<int>(this->_f);
	return ;
}

void	DataType::doubleConv( void ) {

	this->_d =  static_cast<double>(std::strtod(this->_input.c_str(), NULL));

	if (static_cast<int>(this->_d) < 0 || static_cast<int>(this->_d) > 255)
		this->_impossible[CHAR] = true;
	else
		this->_c = static_cast<char>(this->_d);
	if (this->_d < INT_MIN || this->_d > INT_MAX)
		this->_impossible[INT] = true;
	else
		this->_n = static_cast<int>(this->_d);
	this->_f = static_cast<float>(this->_d);
	return ;
}

/* insertion operator overload */

std::ostream &	operator<<( std::ostream & o, DataType const & rhs ) {

	o << std::endl << "char: " << rhs.printChar() << std::endl
	<< "int: ";
	rhs.printInt();
	std::cout << "float: ";
	rhs.printFloat();
	std::cout << "double: ";
	rhs.printDouble();
	return (o);
}
