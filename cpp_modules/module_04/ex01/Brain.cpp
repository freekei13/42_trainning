#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Default constructor is called" << std::endl;
}

Brain::Brain(Brain const& src)
{
    for (int i = 0; i < 100; i++)
        _ideas[i] = src._ideas[i];
    std::cout << "Brain Copy constructor is called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor is called" << std::endl;
}

Brain&  Brain::operator=(Brain const& rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < 100; i++)
            _ideas[i] = rhs._ideas[i];
        std::cout << "Animal Copy assignment operator is called" << std::endl;
    }
    return *this;
}

const std::string&    Brain::getIdea(unsigned int index) const
{
    return  _ideas[index];
}

void    Brain::setIdea(unsigned int index, std::string const& idea)
{
    _ideas[index] = idea;
}