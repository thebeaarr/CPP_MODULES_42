#include "Account.hpp"

int Account::getNbAccounts()
{
    return _nbAccounts;
}

int Account::getNbDeposits()
{
    return _totalNbDeposits;
}
int Account::getTotalAmount()
{
    return _totalAmount;
}

int Account::getNbWithdrawals()
{
    return _totalNbWithdrawals;
}

Account::Account(int initial_deposit ) : _amount(initial_deposit) , _nbWithdrawals(0),_nbDeposits(0)
{

}

void Account::displayAccountsInfos()
{
    // display somehting:
}
