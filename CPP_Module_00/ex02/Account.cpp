#include "Account.hpp"
#include <time.h>
#include <iostream>

int Account::getNbAccounts()
{
	return (t::_nbAccounts);
}

int Account::getTotalAmount()
{
	return (t::_totalAmount);
}

int Account::getNbDeposits()
{
	return (t::_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (t::_totalNbWithdrawals);
}

void	Account::_displayTimestamp()
{
 /*   struct tm *pLocal = localtime(&time_now);
    std::cout << '[' << pLocal->tm_year + 1900 << pLocal->tm_mon << pLocal-> tm_mday << "_"
    << pLocal->tm_hour << pLocal->tm_min << pLocal->tm_sec << "] ";*/
	struct tm	local;
	time_t		time;

	local = *localtime(&time);
	std::cout << '[' << local.tm_year + 1900 << local.tm_mon <<	local.tm_mday; 
	std::cout << '_' << local.tm_hour << local.tm_min << local.tm_sec << "] ";
}

void Account::displayAccountsInfos()
{

}

Account:Account()
{
	Account::_accountIndex = 0;
	Account::_amount = 0;
	Account::_nbDeposits = 0;
	Account::_nbWithdrawals = 0;
}

Account::Account (int initial_deposit)
{
	Account();
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;

}
