#include "Phonebook.hpp"

Phonebook::Phonebook()
{
    nbContact = 0;
}

int Phonebook::getNbContact()
{
    return nbContact;
}

void    Phonebook::addContact()
{
    Contact ct;
    std::string   arg;

    std::cout << "Enter your fist name: ";
    std::cin >> arg;
    ct.setFirstName(arg);

    std::cout << "Enter your last name: ";
    std::cin >> arg;
    ct.setLastName(arg);

    std::cout << "Enter your nick name: ";
    std::cin >> arg;
    ct.setNickName(arg);

    std::cout << "Enter your phone number: ";
    std::cin >> arg;
    ct.setPhoneNumber(arg);

    std::cout << "Enter your darkest secret: ";
    std::cin >> arg;
    ct.setSecret(arg);

    contactList[nbContact % 8] = ct;
    nbContact++;
}

void    Phonebook::viewContactList()
{
    
}