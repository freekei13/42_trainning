#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("FRAG")
{
    _hitPoint = 100;
    _energyPoint = 100;
    _attackDamage = 30;
    std::cout << "FragTrap Default constructor is called" << std::endl;
}

FragTrap::FragTrap(std::string const& name): ClapTrap(name)
{
    _hitPoint = 100;
    _energyPoint = 100;
    _attackDamage = 30;
    std::cout << _name << " FragTrap has been created" << std::endl;
}

FragTrap::FragTrap(FragTrap const& other): ClapTrap(other._name)
{
    _hitPoint = other._hitPoint;
    _energyPoint = other._energyPoint;
    _attackDamage = other._attackDamage;
    std::cout << _name << " FragTrap has been copied" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << _name << " FragTrap has been destroyed" << std::endl;
}

FragTrap&   FragTrap::operator=(FragTrap const& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        std::cout << "FragTrap has been assigned to " << other._name << std::endl;
    }
    return *this;
}

void    FragTrap::highFivesGuys()
{
    std::cout << _name << " FragTrap request a positive high-fives" << std::endl;
}

void    FragTrap::attack(std::string const& target)
{
    if (_hitPoint > 0 && _energyPoint > 0)
    {
        std::cout << "FragTrap " << _name << " attacks " << target;
        std::cout << ", causing " << _attackDamage << " points of damage" << std::endl;
        _energyPoint--;
    }
    else
        std::cout << "FragTrap " << _name << " can't attack" << std::endl;
}

void    FragTrap::takeDamage(unsigned int amount)
{
    if (_hitPoint > 0)
    {
        _hitPoint -= amount;
        std::cout << "FragTrap " << _name << " has taken " << amount;
        std::cout << " points of damage" << std::endl;
        if (_hitPoint <= 0)
            std::cout << "FragTrap " << _name << " has beed destroyed" << std::endl;
        else
            std::cout << "FragTrap " << _name << " has " << _hitPoint << " hit points left" << std::endl;
    }
    else
        std::cout << "FragTrap " << _name << " is already been destroyed" << std::endl;
    
}

void    FragTrap::beRepaired(unsigned int amount)
{
    if (_energyPoint > 0 && _hitPoint > 0)
    {
        _hitPoint += amount;
        _energyPoint--;
        std::cout << "FragTrap " << _name << " repair it self, and restore ";
        std::cout << amount << " hit points" << std::endl;
        std::cout << "FragTrap " << _name << " has " << _hitPoint << " hit points left" << std::endl;
    }
    else
        std::cout << "FragTrap " << _name << " can't repair" << std::endl;
}
