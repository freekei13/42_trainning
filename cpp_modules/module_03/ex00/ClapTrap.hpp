#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <string>
# include <iostream>

class   ClapTrap
{
    private:
        std::string _name;
        int         _hitPoint;
        int         _energyPoint;
        int         _attackDamage;
    public:
        ClapTrap();
        ClapTrap(std::string const& name);
        ClapTrap(ClapTrap const& other);
        ~ClapTrap();
        ClapTrap&   operator=(ClapTrap const& other);
        void        attack(std::string const& target);
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);
};

#endif