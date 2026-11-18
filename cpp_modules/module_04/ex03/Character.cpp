#include "Character.hpp"

Character::Character(): _name("none")
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character(Character const& src): _name(src._name)
{
    for (int i = 0; i < 4; i++)
    {
        if (src._inventory[i])
            _inventory[i] = src._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        delete _inventory[i];
}

Character&  Character::operator=(Character const& rhs)
{
    if (this != &rhs)
    {
        _name = rhs._name;
        for (int i = 0; i < 4; i++)
        {
            delete _inventory[i];
            if (rhs._inventory[i])
                _inventory[i] = rhs._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }
    }
    return *this;
}

Character::Character(std::string const& name): _name(name)
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

std::string const&  Character::getName() const
{
    return _name;
}

void    Character::equip(AMateria* m)
{
    if (!m)
    {
        std::cerr << _name << " can not equip this materia." << std::endl;
        return ;
    }
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i] == m)
        {
            std::cout << _name << " you have already equiped this materia." << std::endl;
            return ;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m;
            std::cout << _name << " has equiped " << m->getType();
            std::cout << " materia at index " << i << "." << std::endl;
            return ;
        }
    }
    std::cout << _name << "'s inventory is full.";
}

void    Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
        std::cout << "Only index 0 to 3 are valide." << std::endl;
    else
    {
        if (_inventory[idx])
        {
            _inventory[idx] = NULL;
            std::cout << _name << " has unequiped a materia." << std::endl;
        }
        else
            std::cout << _name << " can not unequip an empty slot." << std::endl;
    }
}

void    Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3)
        std::cout << "Only index 0 to 3 are valide." << std::endl;
    else
    {
        if (_inventory[idx])
        {
            std::cout << _name << " ";
            _inventory[idx]->use(target);
        }
        else
            std::cout << _name << " can not use an empty slot." << std::endl;
    }
}