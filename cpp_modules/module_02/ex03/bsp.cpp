#include "Point.hpp"

bool    pointCheck(Point const u, Point const v)
{
    Fixed   d(u.getX() * v.getY() - u.getY() * v.getX());
    if (d.toFloat() <= 0)
        return false;
    return true;

}

bool    bsp(Point const a, Point const b, Point const c, Point const point)
{
    bool    vectorStatus;
    Point   u1(b -a);
    Point   v1(point - a);
    Point   u2(c - b);
    Point   v2(point - b);
    Point   u3(a - c);
    Point   v3(point - c);

    vectorStatus = pointCheck(u1, v1);
    if (pointCheck(u2, v2) != vectorStatus)
        return false;
    if (pointCheck(u3, v3) != vectorStatus)
        return false;
    return true;
}