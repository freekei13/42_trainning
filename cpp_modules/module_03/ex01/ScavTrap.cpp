#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("SCAV")
{
    _hitPoint = 100;
    _energyPoint = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap Default constructor is called" << std::endl;
}

ScavTrap::ScavTrap(std::string const& name): ClapTrap(name)
{
    _hitPoint = 100;
    _energyPoint = 50;
    _attackDamage = 20;
    std::cout << _name << " ScavTrap has been created" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& other): ClapTrap(other._name)
{
    _hitPoint = other._hitPoint;
    _energyPoint = other._energyPoint;
    _attackDamage = other._attackDamage;
    std::cout << _name << " ScavTrap has been copied" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << _name << " ScavTrap has been destroyed" << std::endl;
}

ScavTrap&   ScavTrap::operator=(ScavTrap const& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        std::cout << " ScavTrap has been assigned to" << other._name << std::endl;
    }
    return *this;
}

void    ScavTrap::guardGate()
{
    std::cout << _name << " ScavTrap is now in Gate keeper mode" << std::endl;
}

void    ScavTrap::attack(std::string const& target)
{
    if (_hitPoint > 0 && _energyPoint > 0)
    {
        std::cout << "ScavTrap " << _name << " attacks " << target;
        std::cout << ", causing " << _attackDamage << " points of damage" << std::endl;
        _energyPoint--;
    }
    else
        std::cout << "ScavTrap " << _name << " can't attack" << std::endl;
}

void    ScavTrap::takeDamage(unsigned int amount)
{
    if (_hitPoint > 0)
    {
        _hitPoint -= amount;
        std::cout << "ScavTrap " << _name << " has taken " << amount;
        std::cout << " points of damage" << std::endl;
        if (_hitPoint <= 0)
            std::cout << "ScavTrap " << _name << " has beed destroyed" << std::endl;
        else
            std::cout << "ScavTrap " << _name << " has " << _hitPoint << " hit points left" << std::endl;
    }
    else
        std::cout << "ScavTrap " << _name << " is already been destroyed" << std::endl;
    
}

void    ScavTrap::beRepaired(unsigned int amount)
{
    if (_energyPoint > 0 && _hitPoint > 0)
    {
        _hitPoint += amount;
        _energyPoint--;
        std::cout << "ScavTrap " << _name << " repair it self, and restore ";
        std::cout << amount << " hit points" << std::endl;
        std::cout << "ScavTrap " << _name << " has " << _hitPoint << " hit points left" << std::endl;
    }
    else
        std::cout << "ScavTrap " << _name << " can't repair" << std::endl;
}
