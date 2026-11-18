#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {}

Cure::Cure(Cure const& src): AMateria(src) {}

Cure::~Cure() {}

Cure&   Cure::operator=(Cure const& rhs)
{
    if (this != &rhs)
        AMateria::operator=(rhs);
    return *this;
}

AMateria*   Cure::clone() const
{
    AMateria* clone = new Cure(*this);
    return clone;
}

void    Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName();
    std::cout << "'s wounds *" << std::endl;
}