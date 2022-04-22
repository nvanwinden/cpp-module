/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Phonebook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 08:42:39 by nvan-win      #+#    #+#                 */
/*   Updated: 2022/03/10 11:21:36 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"
#include <iomanip>

Phonebook::Phonebook(void) : _idx(0), _totalContacts(0) {

	this->welcome();
	return ;
}

Phonebook::~Phonebook(void) {

	std::cout << std::endl << GREEN << "Good bye!" << RESET << std::endl;
	return ;
}

int 	ft_strlen(std::string s) {

	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

bool	isNumber(std::string s) {

	int	i;

	i = 0;
	while (s[i])
	{
		if (std::isdigit(s[i]) == 0)
			return false;
		i++;
	}
	return (true);
}

void Phonebook::displayContactInformation(std::string index) const {
	
	std::cout << std::endl << std::left << std::setw(18) << "First name:" << _contact[std::stoi(index)].getFirstName() << std::endl;
	std::cout << std::left << std::setw(18) << "Last name:" << _contact[std::stoi(index)].getLastName() << std::endl;
	std::cout << std::left << std::setw(18) << "Nickname:" << _contact[std::stoi(index)].getNickname() << std::endl;
	std::cout << std::left << std::setw(18) << "Phone number:" << _contact[std::stoi(index)].getPhoneNumber() << std::endl;
	std::cout << std::left << std::setw(18) << "Darkest secret:" << _contact[std::stoi(index)].getDarkestSecret() << std::endl << std::endl;
	return ;
}

void	Phonebook::displayContact(int idx) const {

	std::string	firstName;
	std::string	lastName;
	std::string	nickname;

	firstName = _contact[idx].getFirstName();
	lastName = _contact[idx].getLastName();
	nickname = _contact[idx].getNickname();

	if (ft_strlen(firstName) > 10)
		firstName = firstName.substr(0, 9) + ".";
	if (ft_strlen(lastName) > 10)
		lastName = lastName.substr(0, 9) + ".";
	if (ft_strlen(nickname) > 10)
		nickname = nickname.substr(0, 9) + ".";	

	std::cout << std::right << std::setw(10) << idx << "|"
	<< std::right << std::setw(10) << firstName << "|"
	<< std::right << std::setw(10) << lastName << "|"
	<< std::right << std::setw(10) << nickname << std::endl;
	return ;
}

void	Phonebook::displayAllContacts(void) const {

	if (_totalContacts > 0)
	{
		std::cout << GREEN << std::right << std::setw(10) << "index" << "|" 
		<< std::right << std::setw(10) << "first name" << "|"
		<< std::right << std::setw(10) << "last name" << "|"
		<< std::right << std::setw(10) << "nickname" << RESET << std::endl;
		for (int j = 0; j < _totalContacts; j++)
			displayContact(j);
		std::cout << std::endl;
	}
	return ;
}

int	Phonebook::searchContact( void ) const {

	std::string	input;
	if (this->_totalContacts == 0)
	{
		std::cout << RED << "There are no contacts to display" << RESET << std::endl << std::endl;
		return (0);
	}
	displayAllContacts();
	while (true) {
		std::cout << "enter index of the contact to display" << " > ";
		std::getline(std::cin, input);
		if (std::cin.good() != 1)
			return (1);
		else if (input.empty())
			std::cout << RED << "input field can not be empty" << RESET << std::endl;
		else if (input.find('\t') != std::string::npos)
			std::cout << RED << "tabs are not valid input" << RESET << std::endl;
		else if (!isNumber(input))
			std::cout << RED << "please enter a valid index number" << RESET << std::endl;
		else if (std::stoi(input) < 0 || std::stoi(input) > this->_totalContacts - 1)
			std::cout << RED << "index is out of range" << RESET << std::endl;
		else {
			displayContactInformation(input);
			return (0);
		}
	}
	return (0);
}

void	Phonebook::update_count(void) {

	int	flag;

	flag = true;
	if (this->_totalContacts == 8)
		flag = false;
	if (this->_idx < 8)
		this->_idx++;
	if (flag == true)
		this->_totalContacts++;
	if (this->_idx == 8)
		this->_idx = 0;
	return ;
}

void	Phonebook::assign_info(std::string input, int i) {

	if (i == 0)
		this->_contact[_idx].setFirstName(input);
	else if (i == 1)
		this->_contact[_idx].setLastName(input);
	else if (i == 2)
		this->_contact[_idx].setNickname(input);
	else if (i == 3)
		this->_contact[_idx].setPhoneNumber(input);
	else if (i == 4)
		this->_contact[_idx].setDarkestSecret(input);
	return ;
}

int	Phonebook::addContact() {

	std::string info[5] = {"First name", "Last name", "Nickname", "Phone number", "Darkest secret"};
	std::string input;
	int			flag;

	for (int i = 0; i < 5; i++)
	{
		flag = true;
		while (flag)
		{
			std::cout << info[i] << " > ";
			std::getline(std::cin, input);
			if (std::cin.good() != 1)
				return (1);
			else if (input.empty())
				std::cout << RED << "input field can not be empty" << RESET << std::endl;
			else if (input.find('\t') != std::string::npos)
				std::cout << RED << "tabs are not valid input" << RESET << std::endl;	
			else if (i == 3 && !isNumber(input))
				std::cout << RED << "please enter a sequence of digits" << RESET << std::endl;
			else
			{
				assign_info(input, i);
				flag = false;
			}
		}
	}
	update_count();
	std::cout << GREEN << std::endl << "Contact has been successfully added" << RESET << std::endl << std::endl;
	return (0);
}

void	Phonebook::prompt(void) const {
	
	std::cout << "Please enter one of the following commands:" << std::endl << std::endl;
	std::cout << std::left << std::setw(12) << "ADD" << ITALIC("[add contact]") << std::endl;
	std::cout << std::left << std::setw(12) << "SEARCH" << ITALIC("[search contact]") << std::endl;
	std::cout << std::left << std::setw(12) << "EXIT" << ITALIC("[exit program]") << std::endl << std::endl;
	std::cout << "> ";
	return ;
}

void	Phonebook::welcome(void) const {

	std::cout << std::endl << GREEN <<
	"     ,'\"\"." << std::endl <<
	"     )  ,|" << std::endl <<
	"    /  /,'-." << std::endl <<
	"   /  //  /.`." << std::endl <<
	" ,'  //  /  `.`." << std::endl <<
	"(    )--.`.   //|" << std::endl <<
	"|`--'|   `.`.// |" << std::endl <<
	" `--'      `./  /  Welcome To My" << std::endl <<
	"   |         | /   Awesome PhoneBook!" << std::endl <<
	"   |_________|/    ~ nvan-win" << RESET << std::endl << std::endl << std::endl;
	return ;
}
