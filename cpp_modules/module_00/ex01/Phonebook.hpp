#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "main.hpp"
# include "Contact.hpp"

class Phonebook
{
    private:
        Contact contactList[8];
        int nbContact;
    public:
        Phonebook();
        int getNbContact();
        void    addContact();
        void    viewContact();
};
#endif