/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Replace.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 16:08:25 by nvan-win      #+#    #+#                 */
/*   Updated: 2022/04/06 09:38:12 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>

class Replace {

public:

	Replace( std::string fileName, std::string s1, std::string s2 );
	~Replace( void );

	int		error;

private:

	int		readFile( void );
	void	replaceOccurrence( void );
	void	writeToFile( void );
	int		writeError( std::string message );

	std::string const	_fileName;
	std::string 		_text;
	std::string const	_s1;
	std::string const	_s2;

};

#endif
