#include "Harl.hpp"

void    Harl::debug()
{
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "I love having extra bacon for my "
        << "7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
    std::cout << " I really do!" << std::endl;
}

void    Harl::info()
{
    std::cout << "[INFO]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << " You didn’t put enough bacon in my burger! If you did,"
        << " I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning()
{
    std::cout << "[WARNING]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << " I’ve been coming for years, whereas you started "
        << "working here just last month." << std::endl;
}

void    Harl::error()
{
    std::cout << "[ERROR]" << std::endl;
    std::cout << "This is unacceptable!" << std::endl;
    std::cout << "I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level)
{
    std::string _level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void    (Harl::*comp[4])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    for (int i = 0; i < 4; i++)
    {
        if (_level[i] == level)
            (this->*comp[i])();
    }
}