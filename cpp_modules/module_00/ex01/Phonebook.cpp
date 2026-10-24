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
        std::cout << std::setw(10) << "Index" << "|";
        std::cout << std::setw(10) << "FirstName" << "|";
        std::cout << std::setw(10) << "LastName" << "|";
        std::cout << std::setw(10) << "NickName" << std::endl;
        for (int i = 0; i < nb; i++)
        {
            std::cout << std::setw(10) << i + 1 << "|";
            if (contact[i].getFirstN().length() > 10)
                std::cout << std::setw(9) << contact[i].getFirstN().substr(0, 9) << ".|";
            else
                std::cout << std::setw(10) << contact[i].getFirstN() << "|";
            if (contact[i].getLastN().length() > 10)
                std::cout << std::setw(9) << contact[i].getLastN().substr(0, 9) << ".|";
            else
                std::cout << std::setw(10) << contact[i].getLastN() << "|";
            if (contact[i].getNickN().length() > 10)
                std::cout << std::setw(9) << contact[i].getNickN().substr(0, 9) << "." << std::endl;
            else
                std::cout << std::setw(10) << contact[i].getNickN() << std::endl;
        }
    }
}

void    Phonebook::displayContact() const
{
    if (contactNb !=0)
    {
        std::string arg;
        int nb = 0;
        if (contactNb < 8)
            nb = contactNb;
        else
            nb = 8;
        while (1)
        {
            std::cout << "Enter an index to display contact" << std::endl;
            if (!std::getline(std::cin, arg))
                break ;
            std::stringstream convert;
            convert << arg;
            int index;
            convert >> index;
            std::cout << "arg: " << arg << std::endl;
            std::cout << "index: " << index << std::endl;
            if (index < 1 || index > nb)
                std::cout << "Index doesn't exist, enter index between 1 to " << nb << std::endl;
            else
            {
                std::cout << "Firstname  : " << contact[index - 1].getFirstN() << std::endl;
                std::cout << "Lastname   : " << contact[index - 1].getLastN() << std::endl;
                std::cout << "Nickname   : " << contact[index - 1].getNickN() << std::endl;
                std::cout << "PhoneNumber: " << contact[index - 1].getPhoneN() << std::endl;
                std::cout << "DarkSecret : " << contact[index - 1].getDarkS() << std::endl;
                break ;
            }
        }
    }
}