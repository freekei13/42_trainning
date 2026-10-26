#include "Zombie.hpp"

void    Zombie::announce( void )
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie( std::string name )
{
    _name = name;
}

Zombie::~Zombie( void )
{
    std::cout << _name << ": ByyyyyeeEEE..." << std::endl;
}

Zombie::Zombie( void ){}

void    Zombie::setName( std::string const &name )
{
    _name = name;
}