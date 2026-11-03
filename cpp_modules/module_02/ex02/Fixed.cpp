#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(): _fNumber(0) {}

Fixed::Fixed(const Fixed& other)
{
    *this = other;
}

Fixed::Fixed(const int nb): _fNumber(nb << _fractionBits) {}

Fixed::Fixed(const float nb): _fNumber(roundf(nb * (1 << _fractionBits))) {}

Fixed::~Fixed() {}

//*******************************************************************//

Fixed& Fixed::operator=(const Fixed& other)
{
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

//*******************************************************************//

Fixed   Fixed::operator+(const Fixed& other) const
{
    Fixed sum(this->toFloat() + other.toFloat());
    return sum;
}

Fixed   Fixed::operator-(const Fixed& other) const
{
    Fixed subs(this->toFloat() - other.toFloat());
    return subs;
}

Fixed   Fixed::operator*(const Fixed& other) const
{
    Fixed multi(this->toFloat() * other.toFloat());
    return multi;
}

Fixed   Fixed::operator/(const Fixed& other) const
{
    Fixed division(this->toFloat() / other.toFloat());
    return division;
}

//*******************************************************************//

Fixed   Fixed::operator++(int)
{
    Fixed old(*this);
    _fNumber += 1;
    return old;
}

Fixed&  Fixed::operator++()
{
    _fNumber += 1;
    return *this;
}

Fixed   Fixed::operator--(int)
{
    Fixed old(*this);
    _fNumber -= 1;
    return old;
}

Fixed&  Fixed::operator--()
{
    _fNumber -= 1;
    return *this;
}

//*******************************************************************//

int Fixed::getRawBits() const
{
    return _fNumber;
}

void    Fixed::setRawBits(int const raw)
{
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

//*******************************************************************//

Fixed&  Fixed::min(Fixed& f1, Fixed& f2)
{
    if (f2 < f1)
        return f2;
    return f1;
}

const Fixed&  Fixed::min(const Fixed& f1, const Fixed& f2)
{
    if (f2 < f1)
        return f2;
    return f1;
}

Fixed&  Fixed::max(Fixed& f1, Fixed& f2)
{
    if (f2 > f1)
        return f2;
    return f1;
}

const Fixed&  Fixed::max(const Fixed& f1, const Fixed& f2)
{
    if (f2 > f1)
        return f2;
    return f1;
}

std::ostream&   operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}
