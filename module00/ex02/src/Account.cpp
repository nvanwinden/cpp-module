/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Account.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-win <nvan-win@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 08:43:42 by nvan-win      #+#    #+#                 */
/*   Updated: 2022/03/10 09:33:50 by nvan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( void ) {

	return ;
}

Account::~Account(void) {

	_displayTimestamp();

	std::cout << " index:" <<
	this->_accountIndex <<
	";amount:" <<
	this->_amount <<
	";closed" << std::endl;
	return ;
}

Account::Account( int initial_deposit ) : _nbDeposits(0), _nbWithdrawals(0) {

	this->_accountIndex = getNbAccounts();
	this->_amount = initial_deposit;
	_nbAccounts += 1;
	_totalAmount += initial_deposit;
	_displayTimestamp();

	std::cout << " index:" <<
	this->_accountIndex <<
	";amount:" <<
	this->_amount <<
	";created" << std::endl;
	return ;
}

void Account::displayAccountsInfos( void ) {
	
	_displayTimestamp();

	std::cout << " accounts:" <<
	getNbAccounts() <<
	";total:" <<
	getTotalAmount() <<
	";deposits:" <<
	getNbDeposits() <<
	";withdrawals:" <<
	getNbWithdrawals() << std::endl ;
	return ;
}

void Account::makeDeposit( int deposit ) {

	_displayTimestamp();

	std::cout << " index:" <<
	this->_accountIndex <<
	";p_amount:" << this->_amount <<
	";deposit:" << deposit;

	this->_amount += deposit;
	this->_nbDeposits += 1;
	
	std::cout << ";amount:" <<
	this->_amount <<
	";nb_deposits:" <<
	this->_nbDeposits << std::endl;

	_totalAmount += deposit;
	_totalNbDeposits += 1;
	return ;
}

bool Account::makeWithdrawal( int withdrawal) {

	_displayTimestamp();

	std::cout << " index:" <<
	this->_accountIndex <<
	";p_amount:" << this->_amount <<
	";withdrawal:";

	if (this->_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal;
	this->_amount -= withdrawal;
	this->_nbWithdrawals += 1;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals += 1;

	std::cout << ";amount:" <<
	this->_amount <<
	";nb_withdrawals:" <<
	this->_nbWithdrawals << std::endl;

	return (true);
}

int	Account::checkAmount( void ) const {

	return (this->_amount);
}

void Account::displayStatus( void ) const {
	_displayTimestamp();

	std::cout << " index:" <<
	this->_accountIndex <<
	";amount:" <<
	this->checkAmount() <<
	";deposits:" <<
	this->_nbDeposits <<
	";withdrawals:" <<
	this->_nbWithdrawals << std::endl ;

	return ;
}

void Account::_displayTimestamp(void ) {

	std::time_t	t;
	std::tm		*timePtr;

	t = std::time(NULL);
	timePtr = std::localtime(&t);
	std::cout << "[" << timePtr->tm_year + 1900;
	if ((timePtr->tm_mon + 1) < 10)
		std::cout << '0';
	std::cout << timePtr->tm_mon + 1;
	if (timePtr->tm_mday < 10)
		std::cout << '0';
	std::cout << timePtr->tm_mday;
	std::cout << "_";
	if (timePtr->tm_hour < 10)
		std::cout << '0';
	std::cout << timePtr->tm_hour;
	if (timePtr->tm_min < 10)
		std::cout << '0';
	std::cout << timePtr->tm_min;
	if (timePtr->tm_sec < 10)
		std::cout << '0';
	std::cout << timePtr->tm_sec << "]";

	return ;
}

int	Account::getNbAccounts( void ) {

	return (_nbAccounts);
}

int Account::getTotalAmount( void ) {

	return (_totalAmount);
}

int Account::getNbDeposits(void ) {

	return (_totalNbDeposits);
}

int Account::getNbWithdrawals( void ) {

	return (_totalNbWithdrawals);
}
