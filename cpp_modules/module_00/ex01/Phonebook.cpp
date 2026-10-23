#include "Phonebook.hpp"

Phonebook::Phonebook()
{
    contactNb = 0;
}

void    Phonebook::addContact(std::string const &fN, std::string const &lN,
            std::string const &nN, std::string const &pN, std::string const &dS)
{
    int index = contactNb % 8;
    
    contact[index].setFirstN(fN);
    contact[index].setLastN(lN);
    contact[index].setNickN(nN);
    contact[index].setPhoneN(pN);
    contact[index].setDarkS(dS);
    contactNb++;
    std::cout << "Contact saved at index: " << index + 1 << std::endl;
}

void    Phonebook::searchContact() const
{
    int nb = 0;
    if (contactNb < 8)
        nb = contactNb;
    else
        nb = 8;
    std::cout << "You have " << nb <<" contacts" << std::endl;
    if (nb > 0)
    {
        std::cout << "Index |" << std::setw(10) << "FirstName" << std::setw(10) << "|"
            << "LastName" << std::setw(10) << "|" << "NickName" << std::setw(10) << std::endl;
    }
}