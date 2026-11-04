#include "Point.hpp"

Point::Point(): _x(0), _y(0) {}

Point::Point(const float x, const float y): _x(x), _y(y) {}

Point::Point(const Point& other): _x(other._x), _y(other._y) 
{
    *this = other;
}

Point::~Point() {}

Point&  Point::operator=(const Point& other)
{
    (void)other;
    return *this;
}

Point   Point::operator-(const Point& other) const
{
    Point subs(_x.toFloat() - other._x.toFloat(), _y.toFloat() - other._y.toFloat());
    return subs;
}

Point   Point::operator*(const Point& other) const
{
    Point multi(_x.toFloat() * other._x.toFloat(), _y.toFloat() * other._y.toFloat());
    return multi;
}

const Fixed& Point::getX() const
{
    return _x;
}

const Fixed& Point::getY() const
{
    return _y;
}