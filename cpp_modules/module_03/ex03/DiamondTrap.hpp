#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
    private:
        std::string _name;
    public:
        DiamondTrap();
        DiamondTrap(std::string const& name);
        DiamondTrap(DiamondTrap const& other);
        ~DiamondTrap();
        DiamondTrap&    operator=(DiamondTrap const& other);
        void            whoAmI();
        void            attack(std::string const& target);
        void            takeDamage(unsigned int amount);
        void            beRepaired(unsigned int amount);
        int             getEnergyPoint() const;
};

#endif