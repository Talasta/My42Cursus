/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 19:36:57 by cmaxime           #+#    #+#             */
/*   Updated: 2019/03/25 19:37:00 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Account.class.hpp"
#include <iostream>

// Public ********************************************************************//


int	    Account::getNbAccounts( void ) {
    return Account::_nbAccounts;
}

int	    Account::getTotalAmount( void ) {
    return Account::_totalAmount;
}

int	    Account::getNbDeposits( void ) {
    return Account::_totalNbDeposits;
}

int	    Account::getNbWithdrawals( void ) {
    return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {

    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";";
    std::cout << "total:" << Account::getTotalAmount() << ";";
    std::cout << "deposits:" << Account::getNbDeposits() << ";";
    std::cout << "withdrawals:" << Account::getNbWithdrawals();
    std::cout << std::endl;

    return ;
}

Account::Account(int initial_deposit) {

    this->_accountIndex = Account::_nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    Account::_nbAccounts += 1;
    Account::_totalAmount += initial_deposit;

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "created" << std::endl;

    return ;
}

Account::~Account( void ) {

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "closed" << std::endl;

    return ;
}

void	Account::makeDeposit( int deposit ) {

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    std::cout << "deposit:" << deposit << ";";

    this->_nbDeposits += 1;
    this->_amount += deposit;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits += 1;

    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_deposits:" << this->_nbDeposits;
    std::cout << std::endl;

    return ;
}

bool	Account::makeWithdrawal( int withdrawal ) {

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";

    if (this->checkAmount() < withdrawal) {
        std::cout << "withdrawal:refused" << std::endl;
        return 0;
    } else {
        std::cout << "withdrawal:" << withdrawal << ";";
    }

    this->_nbWithdrawals += 1;
    this->_amount -= withdrawal;
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals += 1;

    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_withdrawals:" << this->_nbWithdrawals;
    std::cout << std::endl;

    return 1;
}

int		Account::checkAmount( void ) const {
    return this->_amount;
}

void	Account::displayStatus( void ) const {

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals;
    std::cout << std::endl;

    return ;
}

// Private *******************************************************************//

void	Account::_displayTimestamp( void ) {
    char buff[20];
	struct tm *sTm;
	time_t now = time (0);
	sTm = gmtime (&now);
	strftime(buff, sizeof(buff), "[%Y%m%d_%H%M%S] ", sTm);
	std::string log_entry(buff);

    std::cout << log_entry;

    return ;
}

int     Account::_nbAccounts = 0;
int     Account::_totalAmount = 0;
int     Account::_totalNbDeposits = 0;
int     Account::_totalNbWithdrawals = 0;
