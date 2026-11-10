#include "FragTrap.hpp"

int main()
{
    FragTrap a;
    a.attack("a dog");
    
    FragTrap b("F1");
    b.attack("a cat");
    b.takeDamage(20);
    b.highFivesGuys();
    b.beRepaired(3);

    FragTrap c;
    c.takeDamage(10);
    c.beRepaired(3);

    c = a;

    return 0;
}