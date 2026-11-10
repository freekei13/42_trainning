#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class   FragTrap: public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string const& name);
        FragTrap(FragTrap const& other);
        ~FragTrap();
        FragTrap&   operator=(FragTrap const& other);
        void        highFivesGuys();
        void        attack(std::string const& target);
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);
};

#endif