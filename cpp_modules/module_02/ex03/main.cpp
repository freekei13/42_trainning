#include "Point.hpp"

int main( void ) 
{
   Point a(3, 6);
   Point b(5.5f, -3.6f);
   Point c(-8, 7.6f);
   Point point(3.7f, -11);
   if (bsp(a, b, c, point))
      std::cout << "point is in triangle a b c" << std::endl;
   else
      std::cout << "point is not in triangle a b c" << std::endl;
   return 0;
}