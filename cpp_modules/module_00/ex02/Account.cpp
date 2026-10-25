#include "Account.hpp"
#include <ctime>
#include <iostream>

int  Account::getNbAccounts( void )
{
    return _nbAccounts;
}

int Account::getTotalAmount( void )
{
    return _totalAmount;
}

int Account::getNbDeposits( void )
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}

void    Account::_displayTimestamp( void )
{
    time_t  rawTime;
    struct tm   *timeInfo;
    time(&rawTime);
    timeInfo = localtime(&rawTime);
    char    timeStamp[17];
    strftime(timeStamp, 17, "[%G%m%d_%H%M%S]", timeInfo);
    std::cout << timeStamp;
}

void    Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << " accounts:" << _nbAccounts << ";";
    std::cout << "total:" << _totalAmount << ";";
    std::cout << "deposits:" << _totalNbDeposits << ";";
    std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account( int initial_deposit )
{
    _displayTimestamp();
    std::cout << 
}