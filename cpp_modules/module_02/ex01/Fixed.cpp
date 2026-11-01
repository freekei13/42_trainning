#include "Fixed.hpp"

Fixed::Fixed(): _fNumber(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other): _fNumber(other._fNumber)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int nb): _fNumber(nb << _fractionBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float nb): _fNumber(nb * (1 << _fractionBits))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_fNumber = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _fNumber;
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    _fNumber = raw;
}

float   Fixed::toFloat() const
{
    return _fNumber / (1 << _fractionBits);
}

int Fixed::toInt() const
{
    return _fNumber >> _fractionBits;
}

std::ostream&   operator<<(const std::ostream& out, const Fixed& fixed)
{
    
}
