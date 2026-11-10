#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): 
    ClapTrap("DIAMOND_clap_name"),
    ScavTrap(), 
    FragTrap(),
    _name("DIAMOND")
{
    _hitPoint = FragTrap::_hitPoint;
    _energyPoint = 50;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap Default constructor is called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string const& name):
    ClapTrap(name + "_clap_name"),
    ScavTrap(name),
    FragTrap(name),
    _name(name)
{
    _hitPoint = FragTrap::_hitPoint;
    _energyPoint = 50;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << _name << " DiamondTrap has been created" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const& other):
    ClapTrap(other._name + "_clap_name"),
    ScavTrap(other),
    FragTrap(other),
    _name(other._name)
{
    _hitPoint = other._hitPoint;
    _energyPoint = other._energyPoint;
    _attackDamage = other._attackDamage;
    std::cout << _name << " DiamondTrap has been copied" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << _name << " DiamondTrap has been destroyed" << std::endl;
}

DiamondTrap&    DiamondTrap::operator=(DiamondTrap const& other)
{
    if (this != &other)
    {
        _name = other._name;
        ClapTrap::operator=(other);
        std::cout << "DiamondTrap has been assigned to " << other._name << std::endl;
    }
    return *this;
}

void    DiamondTrap::whoAmI()
{
    std::cout << "my name is " << _name << " and my origin name is " << ClapTrap::_name << std::endl;
}

void    DiamondTrap::attack(std::string const& target)
{
    ScavTrap::attack(target);
}

void    DiamondTrap::takeDamage(unsigned int amount)
{
    if (_hitPoint > 0)
    {
        _hitPoint -= amount;
        std::cout << "DiamondTrap " << _name << " has taken " << amount;
        std::cout << " points of damage" << std::endl;
        if (_hitPoint <= 0)
            std::cout << "DiamondTrap " << _name << " has beed destroyed" << std::endl;
        else
            std::cout << "DiamondTrap " << _name << " has " << _hitPoint << " hit points left" << std::endl;
    }
    else
        std::cout << "DiamondTrap " << _name << " is already been destroyed" << std::endl;
    
}

void    DiamondTrap::beRepaired(unsigned int amount)
{
    if (_energyPoint > 0 && _hitPoint > 0)
    {
        _hitPoint += amount;
        _energyPoint--;
        std::cout << "DiamondTrap " << _name << " repair it self, and restore ";
        std::cout << amount << " hit points" << std::endl;
        std::cout << "DiamondTrap " << _name << " has " << _hitPoint << " hit points left" << std::endl;
    }
    else
        std::cout << "DiamondTrap " << _name << " can't repair" << std::endl;
}

int DiamondTrap::getEnergyPoint() const
{
    return _energyPoint;
}