/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Account.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/21 12:31:22 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/03/21 15:24:41 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalAmount = 0;

Account::Account(void)
{
}

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	this->_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << getNbAccounts() << ";amount:" << checkAmount() << ";created" << std::endl;
	this->_accountIndex = this->_nbAccounts;
	this->_nbAccounts++;
}
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << checkAmount() << ";closed" << std::endl;
	this->_nbAccounts--;
}

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}
int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}
int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}
void Account::_displayTimestamp(void)
{
	std::cout << "[19920104_091532] ";
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount();
	std::cout << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->checkAmount();
	std::cout << ";deposit:" << deposit << ";amount:" << this->checkAmount()
		+ deposit;
	std::cout << ";nb_deposits:" << this->_nbDeposits + 1 << std::endl;
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_nbDeposits += 1;
	this->_totalNbDeposits += 1;
}

bool Account::makeWithdrawal(int withdrawal)
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->checkAmount();
	std::cout << ";withdrawal:";
	if (this->_amount - withdrawal > 0)
	{
		std::cout << withdrawal << ";amount:" << _amount
			- withdrawal << ";nb_withdrawals:" << _nbWithdrawals
			+ 1 << std::endl;
		this->_amount -= withdrawal;
		this->_totalAmount -= withdrawal;
		this->_nbWithdrawals += 1;
		this->_totalNbWithdrawals += 1;
		return (true);
	}
	std::cout << "refused" << std::endl;
	return (false);
}
int Account::checkAmount(void) const
{
	return (this->_amount);
}
