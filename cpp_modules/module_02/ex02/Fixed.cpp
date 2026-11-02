#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(): _fNumber(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed(const int nb): _fNumber(nb << _fractionBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float nb): _fNumber(roundf(nb * (1 << _fractionBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_fNumber = other._fNumber;
    }
    return *this;
}

bool    Fixed::operator>(const Fixed& other) const
{
    if (this->getRawBits() > other.getRawBits())
        return true;
    return false;
}

bool    Fixed::operator<(const Fixed& other) const
{
    if (this->getRawBits() < other.getRawBits())
        return true;
    return false;
}

bool    Fixed::operator>=(const Fixed& other) const
{
    if (this->getRawBits() >= other.getRawBits())
        return true;
    return false;
}

bool    Fixed::operator<=(const Fixed& other) const
{
    if (this->getRawBits() <= other.getRawBits())
        return true;
    return false;
}

bool    Fixed::operator==(const Fixed& other) const
{
    if (this->getRawBits() == other.getRawBits())
        return true;
    return false;
}

bool    Fixed::operator!=(const Fixed& other) const
{
    if (this->getRawBits() != other.getRawBits())
        return true;
    return false;   
}

Fixed&   Fixed::operator+(const Fixed& other)
{
    _fNumber += other.getRawBits();
    return *this;
}

Fixed&   Fixed::operator-(const Fixed& other)
{
    _fNumber -= other.getRawBits();
    return *this;
}

Fixed&   Fixed::operator*(const Fixed& other)
{
    _fNumber *= other.getRawBits();
    return *this;
}

Fixed&   Fixed::operator/(const Fixed& other)
{
    _fNumber /= other.getRawBits();
    return *this;
}

Fixed   Fixed::operator++(int)
{
    Fixed old(*this);
    _fNumber += (1 << _fractionBits);
    return old;
}

Fixed&  Fixed::operator++()
{
    _fNumber += (1 << _fractionBits);
    return *this;
}

Fixed   Fixed::operator--(int)
{
    Fixed old(*this);
    _fNumber -= (1 << _fractionBits);
    return old;
}

Fixed&  Fixed::operator--()
{
    _fNumber -= (1 << _fractionBits);
    return *this;
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
    return (float)_fNumber / (1 << _fractionBits);
}

int Fixed::toInt() const
{
    return _fNumber >> _fractionBits;
}

std::ostream&   operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}

Fixed&  Fixed::min(Fixed& f1, Fixed& f2)
{
    if (f1 < f2)
        return f1;
    return f2;
}

const Fixed&  Fixed::min(const Fixed& f1, const Fixed& f2)
{
    if (f1 < f2)
        return f1;
    return f2;
}
