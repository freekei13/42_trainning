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
        void    addContact();
        void    searchContact() const;
        void    displayContact(int index) const;
};

#endif