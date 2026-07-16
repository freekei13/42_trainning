#include "Phonebook.hpp"
#include <iomanip>

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
    std::cout << nbContact << " contact(s) in the Phonebook" << std::endl;
    std::cout << "Index" << std::setw(10) << "|";
    std::cout << "Firstname" << std::setw(10) << "|";
    std::cout << "Lastname" << std::setw(10) << "|";
    std::cout << "Nickname" << std::setw(10) << std::endl;
    for (int i = 0; i < (nbContact % 8); i++)
    {
        std::cout << i << std::setw(10) << "|";
        std::cout << contactList[i].getFirstName() << std::setw(10) << "|";
        std::cout << contactList[i].getLastName() << std::setw(10) << "|";
        std::cout << contactList[i].getNickName() << std::setw(10) << std::endl;
    }
}

void    Phonebook::viewContact(int index)
{
    
}