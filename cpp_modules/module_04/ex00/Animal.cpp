#include "Animal.hpp"

Animal::Animal(void): _type("Animal") 
{
    std::cout << "Animal Default constructor is called" << std::endl;
}

Animal::Animal(Animal const& src): _type(src._type)
{
    std::cout << "Animal Copy constructor is called" << std::endl;
}

Animal::~Animal(void)
{
    std::cout << "Animal Destructor is called" << std::endl;
}

Animal& Animal::operator=(Animal const& rhs)
{
    if (this != &rhs)
    {
        _type = rhs._type;
        std::cout << "Animal Copy assignment operator is called" << std::endl;
    }
    return *this;
}

std::string    Animal::getType(void) const
{
    return _type;
}

void    Animal::makeSound(void) const
{
    std::cout << "Animal make a sound" << std::endl;
}