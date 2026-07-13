#include "Contact.hpp"

void    Contact::setFirstName(const std::string argument)
{
    firstName = argument;
}

void    Contact::setLastName(const std::string argument)
{
    lastName = argument;
}

void    Contact::setNickName(const std::string argument)
{
    nickName = argument;
}

void    Contact::setPhoneNumber(const std::string argument)
{
    phoneNumber = argument;
}

void    Contact::setSecret(const std::string argument)
{
    darkSecret = argument;
}

std::string Contact::getFirstName() const 
{
    return firstName;
}

std::string Contact::getLastName() const 
{
    return lastName;
}

std::string Contact::getNickName() const 
{
    return nickName;
}

std::string Contact::getPhoneNumber() const 
{
    return phoneNumber;
}

std::string Contact::getSecret() const 
{
    return darkSecret;
}