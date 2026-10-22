#include "Phonebook.hpp"

int main()
{
    Phonebook myPhoneBook;
    std::string arg;

    std::cout << "Welcome to My awesome phonebook" << std::endl;
    while (1)
    {
        std::cout << "Type \"ADD\" to add a contact." << std::endl;
        std::cout << "Type \"SEARCH\" to display saved contacts" << std::endl;
        std::cout << "Type \"EXIT\" t Exit the programe" << std::endl;
        std::cin >> arg;
        if (arg == "ADD")
        {
            myPhoneBook.addContact();
        }
        else if (arg == "SEARCH")
        {

        }
        else if (arg == "EXIT")
        {
            break ;
        }
    }
    return (0);
}