#include "ScavTrap.hpp"

int main()
{
    ScavTrap    a("S1");
    a.attack("something");
    a.takeDamage(10);
    a.beRepaired(5);
    a.guardGate();

    ScavTrap b = a;
    b.takeDamage(2);
    a.takeDamage(0);

    ScavTrap c;
    c.attack("a leg");
    return 0;
}