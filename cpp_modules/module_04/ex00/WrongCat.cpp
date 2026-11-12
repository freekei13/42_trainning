#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal() 
{
    _type = "WrongCat";
    std::cout << "WrongCat Default constructor is called" << std::endl;
}

WrongCat::WrongCat(WrongCat const& src): WrongAnimal(src)
{
    std::cout << "WrongCat Copy constructor is called" << std::endl;
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat Destructor is called" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat const& rhs)
{
    if (this != &rhs)
    {
        WrongAnimal::operator=(rhs);
        std::cout << "WrongCat Copy assignment operator is called" << std::endl;
    }
    return *this;
}

void    WrongCat::makeSound(void) const
{
    std::cout << "WrongCat make a sound" << std::endl;
}
