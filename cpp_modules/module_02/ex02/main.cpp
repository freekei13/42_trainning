#include "Fixed.hpp"

int main( void ) 
{
    // Fixed   a;
    // Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    // std::cout << a << std::endl;
    // std::cout << ++a << std::endl;
    // std::cout << a << std::endl;
    // std::cout << a++ << std::endl;
    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << Fixed::max( a, b ) << std::endl;
    Fixed   a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed const c(42.42f);
    Fixed   d(13);
    Fixed   e(d);

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << "e: " << e << std::endl;

    std::cout << "a > b:" << std::endl;
    if (a > b)
        std::cout << a << " is greater than " << b << ": true" << std::endl;
    else
        std::cout << a << " is not greater than " << b << ": false" << std::endl;
    std::cout << "a = d" << std::endl;
    std::cout << "a < b:" << std::endl;
    a = d;
    if (a < b)
        std::cout << a << " is smaller than " << b << ": true" << std::endl;
    else
        std::cout << a << " is not smaller than " << b << ": false" << std::endl;
    std::cout << "a == e:" << std::endl;
    if (a == e)
        std::cout << a << " is equal to " << e << ": true" << std::endl;
    else
        std::cout << a << " is not equal to " << e << ": false" << std::endl;
    std::cout << "a >= c:" << std::endl;
    if (a >= c)
        std::cout << a << " is greater or equal to " << c << ": true" << std::endl;
    else
        std::cout << a << " is not greater or equal to " << c << ": false" << std::endl;
    std::cout << "c <= b:" << std::endl;
    if (c <= b)
        std::cout << c << " is smaller or equal to " << b << ": true" << std::endl;
    else
        std::cout << c << " is not smaller or equal to " << b << ": false" << std::endl;
    std::cout << "b != e:" << std::endl;
    if (b != e)
        std::cout << b << " is not equal to " << e << ": true" << std::endl;
    else
        std::cout << b << " is equal to " << e << ": false" << std::endl;

    std::cout << " a + b:" << std::endl;
    std::cout << a << " + " << b << " = " << a + b << std::endl;
    std::cout << " b - c:" << std::endl;
    std::cout << b << " - " << c << " = " << b - c << std::endl;
    std::cout << " e * d:" << std::endl;
    std::cout << e << " * " << d << " = " << e * d << std::endl;
    a = 0;
    std::cout << " b / a:" << std::endl;
    std::cout << a << " / " << b << " = " << b / a << std::endl;

    std::cout << "a: " << a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a: " << a << std::endl;

    std::cout << "a--: " << a-- << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "--a: " << --a << std::endl;
    std::cout << "a: " << a << std::endl;
    return 0;
}