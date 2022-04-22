/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Phonebook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 08:42:13 by nvan-win      #+#    #+#                 */
/*   Updated: 2022/03/10 10:49:18 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "./Contact.hpp"
#include <iostream>
#include <string>

#define GREEN		"\033[32;1m"
#define	RED			"\033[31m"
#define RESET		"\033[0m"
#define ITALIC(str)	"\033[3m" str "\033[0m"

class Phonebook {

public:

	Phonebook(void);
	~Phonebook(void);

	void prompt(void) const;
	int	addContact(void);
	int	searchContact(void) const;

private:

	void welcome(void) const;
	void assign_info(std::string input, int i);
	void update_count(void);
	void displayAllContacts(void) const ;
	void displayContact(int idx) const ;
	void displayContactInformation (std::string index) const;

	Contact	_contact[8];
	int		_idx;
	int		_totalContacts;

};

#endif
