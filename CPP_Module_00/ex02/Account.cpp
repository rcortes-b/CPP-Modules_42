#include "Account.hpp"
#include <time.h>
#include <iostream>

//Initialize static private variables to not overwrite in the Account constructor

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
//Getters

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
	struct tm	local;
	time_t		t;

	t = time(NULL);
	local = *localtime(&t);
	std::cout << '[' << local.tm_year + 1900 << 0 << local.tm_mon + 1 <<	local.tm_mday; 
	std::cout << '_' << local.tm_hour << local.tm_min << local.tm_sec << "] ";
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount();
	std::cout << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals();
	std::cout << std::endl;
}

//Used to initialize to 0 every 'Account'

Account::Account()
{
	Account::_accountIndex = 0;
	Account::_amount = 0;
	Account::_nbDeposits = 0;
	Account::_nbWithdrawals = 0;
}

//Initialize and give values to every 'Account'

Account::Account (int initial_deposit)
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

//Destructor

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
	_accountIndex--;
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";deposit:" << deposit << ";amount:" << _amount;
	std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	if (withdrawal > _amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount;
	std::cout << ";nb_withdrawals:" << _nbDeposits << std::endl;
	return (true);
}
