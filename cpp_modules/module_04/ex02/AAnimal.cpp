#include "AAnimal.hpp"

AAnimal::AAnimal(void): _type("AAnimal") 
{
    std::cout << "AAnimal Default constructor is called" << std::endl;
}

AAnimal::AAnimal(AAnimal const& src): _type(src._type)
{
    std::cout << "AAnimal Copy constructor is called" << std::endl;
}

AAnimal::~AAnimal(void)
{
    std::cout << "AAnimal Destructor is called" << std::endl;
}

AAnimal& AAnimal::operator=(AAnimal const& rhs)
{
    if (this != &rhs)
    {
        _type = rhs._type;
        std::cout << "AAnimal Copy assignment operator is called" << std::endl;
    }
    return *this;
}

std::string    AAnimal::getType(void) const
{
    return _type;
}

void    AAnimal::makeSound(void) const
{
    std::cout << "AAnimal make a sound" << std::endl;
}