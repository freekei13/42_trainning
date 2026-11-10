#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("T1");
    a.attack("something");
    a.takeDamage(2);
    a.beRepaired(1);

    ClapTrap b(a);
    b.takeDamage(5);
    a.takeDamage(3);

    ClapTrap c("T2");
    c.attack("T1");
    c.takeDamage(5);
    c.beRepaired(5);
    c = a;
    c.takeDamage(1);
    a.takeDamage(0);
    b.takeDamage(0);
    c.takeDamage(0);
    return 0;
}