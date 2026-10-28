#include "HumanB.hpp"

void    HumanB::attack()
{
    std::cout << _name << " attacks with their ";
    if (!_weapon)
        std::cout << "hands" << std::endl;
    else
        std::cout << _weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon& weapon)
{
    _weapon = &weapon;
}

HumanB::HumanB(std::string const& name): _name(name), _weapon(NULL) {}
