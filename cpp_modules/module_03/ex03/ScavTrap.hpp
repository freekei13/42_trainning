#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class   ScavTrap: virtual public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string const& name);
        ScavTrap(ScavTrap const& other);
        ~ScavTrap();
        ScavTrap&   operator=(ScavTrap const& other);
        void    guardGate();
        void    attack(std::string const& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
};

#endif