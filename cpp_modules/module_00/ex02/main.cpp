#include "Account.hpp"
#include <ctime>
#include <iostream>

int main()
{
    time_t  rawTime;
    struct tm   *timeInfo;
    time(&rawTime);
    timeInfo = localtime(&rawTime);
    char    timeStamp[18];
    strftime(timeStamp, 18, "[%G%m%d_%H%M%S]", timeInfo);
    std::cout << timeStamp;
}