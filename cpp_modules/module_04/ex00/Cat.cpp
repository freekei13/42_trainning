#include "Cat.hpp"

Cat::Cat(void): Animal() 
{
    _type = "Cat";
    std::cout << "Cat Default constructor is called" << std::endl;
}

Cat::Cat(Cat const& src): Animal(src)
{
    std::cout << "Cat Copy constructor is called" << std::endl;
}

Cat::~Cat(void)
{
    std::cout << "Cat Destructor is called" << std::endl;
}

Cat& Cat::operator=(Cat const& rhs)
{
    if (this != &rhs)
    {
        Animal::operator=(rhs);
        std::cout << "Cat Copy assignment operator is called" << std::endl;
    }
    return *this;
}

void    Cat::makeSound(void) const
{
    std::cout << "Cat make a sound" << std::endl;
}
