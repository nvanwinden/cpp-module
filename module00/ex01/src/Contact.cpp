/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 08:42:28 by nvan-win      #+#    #+#                 */
/*   Updated: 2022/03/10 10:02:49 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

Contact::Contact(void) {

	return ;
}

Contact::~Contact(void) {

	return ;
}

std::string Contact::getFirstName(void) const {

	return (this->_firstName);
}

std::string Contact::getLastName(void) const {

	return (this->_lastName);
}

std::string Contact::getNickname(void) const {

	return (this->_nickName);
}

std::string Contact::getPhoneNumber(void) const {

	return (this->_phoneNumber);
}

std::string Contact::getDarkestSecret(void) const {

	return (this->_darkestSecret);
}

void Contact::setFirstName(std::string firstName) {

	this->_firstName = firstName;
	return ;
}

void Contact::setLastName(std::string lastName) {

	this->_lastName = lastName;
	return ;
}

void Contact::setNickname(std::string nickName) {

	this->_nickName = nickName;
	return ;
}

void Contact::setPhoneNumber(std::string phoneNumber) {

	this->_phoneNumber = phoneNumber;
	return ;
}

void Contact::setDarkestSecret(std::string darkestSecret) {

	this->_darkestSecret = darkestSecret;
	return ;
}
