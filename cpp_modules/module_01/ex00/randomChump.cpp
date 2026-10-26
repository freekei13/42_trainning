#include "Zombie.hpp"

void    randomChump( std::string name )
{
    Zombie randChump(name);
    randChump.announce();
}