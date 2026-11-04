#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
    private:
        Fixed const _x;
        Fixed const _y;
    public:
        Point();
        Point(const float x, const float y);
        Point(const Point& other);
        ~Point();
        Point& operator=(const Point& other);
        Point operator-(const Point& other) const;
        Point operator*(const Point& other) const;
        const Fixed& getX() const;
        const Fixed& getY() const;
};

bool    bsp(Point const a, Point const b, Point const c, Point const point);
bool    pointCheck(Point const u, Point const v);
#endif