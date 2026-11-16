#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {}

Ice::Ice(Ice const& src): AMateria(src) {}

Ice::~Ice() {}

Ice&    Ice::operator=(Ice const& rhs)
{
    if (this != &rhs)
        _type = rhs._type;
    return *this;
}

AMateria*   Ice::clone() const
{
    AMateria*   clone = new Ice();
    return  clone;
}

void    Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName();
    std::cout << " *" << std::endl;
}