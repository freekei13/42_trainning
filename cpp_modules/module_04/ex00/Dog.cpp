#include "Dog.hpp"

Dog::Dog(void): Animal() 
{
    _type = "Dog";
    std::cout << "Dog Default constructor is called" << std::endl;
}

Dog::Dog(Dog const& src): Animal(src)
{
    std::cout << "Dog Copy constructor is called" << std::endl;
}

Dog::~Dog(void)
{
    std::cout << "Dog Destructor is called" << std::endl;
}

Dog& Dog::operator=(Dog const& rhs)
{
    if (this != &rhs)
    {
        Animal::operator=(rhs);
        std::cout << "Dog Copy assignment operator is called" << std::endl;
    }
    return *this;
}

void    Dog::makeSound(void) const
{
    std::cout << "Dog make a sound" << std::endl;
}
