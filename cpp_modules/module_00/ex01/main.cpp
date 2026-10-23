#include "Phonebook.hpp"

std::string    promptAdd(std::string name)
{
    std::string arg;
    while (1)
    {
        std::cout << "Enter " << name << ":" << std::endl;
        std::getline(std::cin, arg);
        if (arg.find_first_not_of(" \t") != std::string::npos)
            return arg;
        std::cout << "You can not enter an empty field" << std::endl;
    }
}

int main()
{
    Phonebook myPhoneBook;
    std::string arg;

    std::cout << "Welcome to My awesome phonebook" << std::endl;
    while (1)
    {
        std::cout << "Type \"ADD\" to add a contact." << std::endl;
        std::cout << "Type \"SEARCH\" to display saved contacts" << std::endl;
        std::cout << "Type \"EXIT\" to Exit the programme" << std::endl;
        std::getline(std::cin, arg);
        if (arg == "ADD")
        {
            std::string firstName = promptAdd("firstname");
            std::string lastName = promptAdd("lastname");
            std::string nickName = promptAdd("nickname");
            std::string phoneNumber = promptAdd("phone number");
            std::string darkSecret = promptAdd("darkest secret");
            myPhoneBook.addContact(firstName, lastName, nickName, phoneNumber, darkSecret);
        }
        else if (arg == "SEARCH")
        {
            myPhoneBook.searchContact();
        }
        else if (arg == "EXIT")
        {
            break ;
        }
    }
    std::cout << "Closing My awesome phonebook" << std::endl;
    std::cout << "You loose all your data..." << std::endl;
    return (0);
}