/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Replace.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 16:11:36 by nvan-win      #+#    #+#                 */
/*   Updated: 2022/03/18 11:52:34 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Replace.hpp"

#include <fstream>

Replace::Replace( std::string fileName, std::string s1, std::string s2 ) : error(0), _fileName(fileName), _s1(s1), _s2(s2) { 

	if (readFile())
		return ;	
	if (this->_s1.compare(this->_s2) == 0)
		return ;
	replaceOccurrence();
	return ;
}

Replace::~Replace( void ) {

	if (this->error == 0)
		writeToFile();
	return ;
}

int	Replace::writeError( std::string message )
{
	this->error = 1;
	std::cout << message << std::endl;
	return (1);
}

int	Replace::readFile( void ) {

	std::ifstream	ifs(this->_fileName, std::ios::in);
	if (!ifs)
		return (writeError(this->_fileName + ": file doesn't exist"));
	std::getline(ifs, this->_text, '\0');
	ifs.close();
	return (0);
}

void Replace::replaceOccurrence( void ) {

	size_t	pos;

	pos = this->_text.find(this->_s1);
	if (this->_s1[0] == '\0')
		return ;
	while (pos != std::string::npos)
	{
		this->_text.erase(pos, this->_s1.length());
		this->_text.insert(pos, this->_s2);
		pos = this->_text.find(this->_s1, pos);
	}
	return ;
}

void Replace::writeToFile( void ) {

	std::ofstream newFile;

	newFile.open(this->_fileName + ".replace");
	newFile << this->_text;
	newFile.close();
	return ;
}
