#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: 1 parameter is needed" << std::endl;
        return (1);
    }
    Harl karen;
    karen.complain(av[1]);
    return (0);
}