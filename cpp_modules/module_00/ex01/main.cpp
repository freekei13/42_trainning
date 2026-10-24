#include "Phonebook.hpp"

void    promptAdd(std::string name, std::string &var)
{
    std::string arg;
    while (1)
    {
        std::cout << "Enter " << name << ":" << std::endl;
        if (!std::getline(std::cin, arg))
            break ;
        if (!arg.find_first_not_of(" \t"))
        {
            var = arg;
            break ;
        }
        std::cout << "You can not enter an empty field" << std::endl;
    }
}

int main()
{
    Phonebook myPhoneBook;

    std::cout << "Welcome to My awesome phonebook" << std::endl;
    while (1)
    {
        std::cout << "Type \"ADD\" to add a contact." << std::endl;
        std::cout << "Type \"SEARCH\" to display saved contacts" << std::endl;
        std::cout << "Type \"EXIT\" to Exit the programme" << std::endl;
        std::string arg;
        if (!std::getline(std::cin, arg))
        {
            std::cout << "Exit...." << std::endl;
            break ;
        }
        if (arg == "ADD")
        {
            std::string firstName;
            std::string lastName;
            std::string nickName;
            std::string phoneNumber;
            std::string darkSecret;
            promptAdd("firstname", firstName);
            promptAdd("lastname", lastName);
            promptAdd("nickname", nickName);
            promptAdd("phone number", phoneNumber);
            promptAdd("darkest secret", darkSecret);
            myPhoneBook.addContact(firstName, lastName, nickName, phoneNumber, darkSecret);
        }
        else if (arg == "SEARCH")
        {
            myPhoneBook.searchContact();
            myPhoneBook.displayContact();
        }
        else if (arg == "EXIT")
            break ;
    }
    std::cout << "Closing My awesome phonebook" << std::endl;
    std::cout << "You loose all your data..." << std::endl;
    return (0);
}