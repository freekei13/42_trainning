#include "Phonebook.hpp"

Phonebook::Phonebook()
{
    contactNb = 0;
}

void    Phonebook::addContact()
{
    int index = contactNb % 8;
    std::string arg;
    
    std::cout << "-----Add Contact-----" << std::endl;
    std::cout << "Enter your first name" << std::endl;
    std::getline(std::cin, arg);
    contact[index].setFirstN(arg);
    std::cout << "Enter your last name" << std::endl;
    std::getline(std::cin, arg);
    contact[index].setLastN(arg);
    std::cout << "Enter your nickname" << std::endl;
    std::getline(std::cin, arg);
    contact[index].setNickN(arg);
    std::cout << "Enter your phone number" << std::endl;
    std::getline(std::cin, arg);
    contact[index].setPhoneN(arg);
    std::cout << "Enter your darkest secret" << std::endl;
    std::getline(std::cin, arg);
    contact[index].setDarkS(arg);
    contactNb++;
}