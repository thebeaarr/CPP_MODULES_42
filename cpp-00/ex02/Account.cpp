#include "Account.hpp"
#include <iostream>
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts() { return _nbAccounts; }

int Account::getTotalAmount() { return _totalAmount; }

int Account::getNbDeposits() { return _totalNbDeposits; }

int Account::getNbWithdrawals() { return _totalNbWithdrawals; }

Account::Account(int initial_depost) {
    _amount = initial_depost;
    _totalAmount += initial_depost;
    _nbDeposits++;
    _nbWithdrawals = 0;
    _accountIndex = _nbAccounts;
    this->_displayTimestamp();
    std::cout << "index:" << _nbAccounts << ";amount" << _amount << ";created" << std::endl;
}

void Account::displayAccountsInfos() {
    std::cout << "accounts:" << _nbAccounts + 1 << ";total:" << _totalAmount;
    std::cout << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals
              << std::endl;
}

void Account::displayStatus() const {
    std::cout << "index:" << _accountIndex << ";amount" << _amount << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals;
}

void Account::makeDeposit(int deposit)
{
    _totalNbDeposits++;
    _nbDeposits++;
    _amount += deposit;
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << _nbDeposits ;
    std::cout << ";amount" << _totalAmount << ";nb_deposits:" << _totalNbDeposits << std::endl;
}

bool Account::
