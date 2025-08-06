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
    _nbDeposits= 0;
    _nbWithdrawals = 0;
    _accountIndex = _nbAccounts;
    this->_displayTimestamp();
    std::cout << "index:" << _nbAccounts << ";amount" << _amount << ";created" << std::endl;
}

void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts + 1 << ";total:" << _totalAmount;
    std::cout << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals
              << std::endl;
}

void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals << std::endl;
}


void Account::makeDeposit(int deposit)
{
    _totalNbDeposits++;
    _nbDeposits++;
    _totalAmount += deposit;
    _amount += deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << _nbDeposits ;
    std::cout << ";amount" << _totalAmount << ";nb_deposits:" << _totalNbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    if(withdrawal <= _amount)
    {
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        std::cout << "index:" << _accountIndex;
        std::cout << ";p_amount" << _amount;
        std::cout << ";withdrawal:" << _nbWithdrawals;
        std::cout << ";amount:" << _totalAmount;
        std::cout << ";nb_withdrawal:" << _totalNbWithdrawals << std::endl;
        return true;
    }
        std::cout << "index:" << _accountIndex;
        std::cout << ";p_amount" << _amount;
        std::cout << ";withdrawal:" << _nbWithdrawals;
        std::cout << ";amount:" << _totalAmount;
        std::cout << ";nb_withdrawal:refused" << std::endl;

        return false;
}

Account::~Account(){
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount" << _amount;
    std::cout << ";deposits" << _nbDeposits;
    std::cout << ";closed" << std::endl;
}


#include <iostream>
#include <ctime>
#include <iomanip>

void Account::_displayTimestamp()
{
    std::time_t now = std::time(NULL);
    std::tm* timeinfo = std::localtime(&now);

    std::cout << '['
              << (timeinfo->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << (timeinfo->tm_mon + 1)
              << std::setw(2) << std::setfill('0') << timeinfo->tm_mday
              << '_'
              << std::setw(2) << std::setfill('0') << timeinfo->tm_hour
              << std::setw(2) << std::setfill('0') << timeinfo->tm_min
              << std::setw(2) << std::setfill('0') << timeinfo->tm_sec
              << "] ";
}
