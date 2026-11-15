#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(AMateria const& src): _type(src._type) {}

AMateria::~AMateria() {}

AMateria&   AMateria::operator=(AMateria const& rhs)
{
    if (this != &rhs)
        _type = rhs._type;
    return *this;
}

AMateria::AMateria(std::string const& type): _type(type) {}

std::string const&  AMateria::getType() const
{
    return _type;
}

AMateria*   AMateria::clone() const
{

}