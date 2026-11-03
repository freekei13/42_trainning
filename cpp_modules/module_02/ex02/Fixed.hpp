#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class Fixed
{
    private:
        int _fNumber;
        static const int _fractionBits = 8;
    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed(const int nb);
        Fixed(const float nb);
        ~Fixed();
        Fixed&  operator=(const Fixed& other);

        bool    operator>(const Fixed& other) const;
        bool    operator<(const Fixed& other) const;
        bool    operator>=(const Fixed& other) const;
        bool    operator<=(const Fixed& other) const;
        bool    operator==(const Fixed& other) const;
        bool    operator!=(const Fixed& other) const;

        Fixed   operator+(const Fixed& other);
        Fixed   operator-(const Fixed& other);
        Fixed   operator*(const Fixed& other);
        Fixed   operator/(const Fixed& other);

        Fixed   operator++(int);
        Fixed&  operator++();
        Fixed   operator--(int);
        Fixed&  operator--();

        int     getRawBits() const;
        void    setRawBits(int const raw);
        float   toFloat() const;
        int     toInt() const;
        
        static  Fixed&  min(Fixed& f1, Fixed& f2);
        static  const Fixed&  min(const Fixed& f1, const Fixed& f2);
        
        static  Fixed&  max(Fixed& f1, Fixed& f2);
        static  const Fixed&  max(const Fixed& f1, const Fixed& f2);
};
    
std::ostream&   operator<<(std::ostream& out, const Fixed& fixed);


#endif