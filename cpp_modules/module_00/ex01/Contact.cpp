#include "Contact.hpp"

void    Contact::setFirstN(std::string const &arg)
{
    firstN = arg;
}

void    Contact::setLastN(std::string const &arg)
{
    lastN = arg;
}

void    Contact::setNickN(std::string const &arg)
{
    nickN = arg;
}

void    Contact::setPhoneN(std::string const &arg)
{
    phoneN = arg;
}

void    Contact::setDarkS(std::string const &arg)
{
    darkS = arg;
}

std::string Contact::getFirstN() const
{
    return firstN;
}

std::string Contact::getLastN() const
{
    return lastN;
}

std::string Contact::getNickN() const
{
    return nickN;
}

std::string Contact::getPhoneN() const
{
    return phoneN;
}

std::string Contact::getDarkS() const
{
    return darkS;
}
