#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): _type("WrongAnimal") 
{
    std::cout << "WrongAnimal Default constructor is called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& src): _type(src._type)
{
    std::cout << "WrongAnimal Copy constructor is called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal Destructor is called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& rhs)
{
    if (this != &rhs)
    {
        _type = rhs._type;
        std::cout << "WrongAnimal Copy assignment operator is called" << std::endl;
    }
    return *this;
}

std::string    WrongAnimal::getType(void) const
{
    return _type;
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal make a sound" << std::endl;
}