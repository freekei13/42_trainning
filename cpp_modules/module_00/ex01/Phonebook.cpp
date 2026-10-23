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