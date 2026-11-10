#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap a("D1");
    a.attack("something");
    std::cout << "EnergyPoint: " << a.getEnergyPoint() << std::endl;
    a.whoAmI();
    a.takeDamage(20);
    a.beRepaired(15);
    std::cout << "EnergyPoint: " << a.getEnergyPoint() << std::endl;

    DiamondTrap b(a);
    b.attack("nothing");
    std::cout << "EnergyPoint: " << b.getEnergyPoint() << std::endl;
    std::cout << "EnergyPoint: " << a.getEnergyPoint() << std::endl;

    DiamondTrap c("D###");

    b = c;
    b.attack("a dog");
    b.takeDamage(0);
    std::cout << "EnergyPoint: " << b.getEnergyPoint() << std::endl;
    b.whoAmI();
    c.whoAmI();

    return 0;
}