#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("T1");
    a.attack("something");
    a.takeDamage(2);
    a.beRepaired(1);

    ClapTrap b(a);
    b.takeDamage(5);
    a.takeDamage(10);


}