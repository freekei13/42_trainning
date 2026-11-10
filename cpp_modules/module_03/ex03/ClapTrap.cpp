#include "ClapTrap.hpp"

ClapTrap::ClapTrap():
    _name("CLAP"), 
    _hitPoint(10),
    _energyPoint(10), 
    _attackDamage(0)
{
    std::cout << "ClapTrap Default constructor is called" << std::endl;
}

ClapTrap::ClapTrap(std::string const& name): _name(name), _hitPoint(10),
    _energyPoint(10), _attackDamage(0)
{
    std::cout << _name << " ClapTrap has been created" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& other): 
    _name(other._name),
    _hitPoint(other._hitPoint), 
    _energyPoint(other._energyPoint),
    _attackDamage(other._attackDamage)
{
    std::cout << _name << " ClapTrap has beed copied" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << _name << " ClapTrap has been destroyed" << std::endl;
}

ClapTrap&   ClapTrap::operator=(ClapTrap const& other)
{
    if (this != &other)
    {
        _name = other._name;
        _hitPoint = other._hitPoint;
        _energyPoint = other._energyPoint;
        _attackDamage = other._attackDamage;
        std::cout << "ClapTrap has been assigned to " << other._name << std::endl;
    }
    return *this;
}

void    ClapTrap::attack(std::string const& target)
{
    if (_hitPoint > 0 && _energyPoint > 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target;
        std::cout << ", causing " << _attackDamage << " points of damage" << std::endl;
        _energyPoint--;
    }
    else
        std::cout << "ClapTrap " << _name << " can't attack" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoint > 0)
    {
        _hitPoint -= amount;
        std::cout << "ClapTrap " << _name << " has taken " << amount;
        std::cout << " points of damage" << std::endl;
        if (_hitPoint <= 0)
            std::cout << "ClapTrap " << _name << " has beed destroyed" << std::endl;
        else
            std::cout << "ClapTrap " << _name << " has " << _hitPoint << " hit points left" << std::endl;
    }
    else
        std::cout << "ClapTrap " << _name << " is already been destroyed" << std::endl;
    
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoint > 0 && _hitPoint > 0)
    {
        _hitPoint += amount;
        _energyPoint--;
        std::cout << "ClapTrap " << _name << " repair it self, and restore ";
        std::cout << amount << " hit points" << std::endl;
        std::cout << "ClapTrap " << _name << " has " << _hitPoint << " hit points left" << std::endl;
    }
    else
        std::cout << "ClapTrap " << _name << " can't repair" << std::endl;
}
