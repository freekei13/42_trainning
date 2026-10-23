#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <iomanip>
# include <iostream>

class   Phonebook
{
    private:
        Contact contact[8];
        int contactNb;
    public:
        Phonebook();
        void    addContact(std::string const &fN, std::string const &lN,
            std::string const &nN, std::string const &pN, std::string const &dS);
        void    searchContact() const;
        void    displayContact(int index) const;
};

#endif