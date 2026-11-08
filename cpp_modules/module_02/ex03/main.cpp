#include "Point.hpp"

int main( void ) 
{
   Point a(300, 0);
   Point b(0, 300);
   Point c(0, 0);
   Point point(0.001, 0);
   if (bsp(a, b, c, point))
      std::cout << "point is in triangle abc" << std::endl;
   else
      std::cout << "point is not in triangle abc" << std::endl;
   return 0;
}