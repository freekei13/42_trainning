#ifndef FIXED_HPP
# define FIXED_HPP

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
        int     getRawBits() const;
        void    setRawBits(int const raw);
        float   toFloat() const;
        int     toInt() const;
};
    
std::ostream&   operator<<(const std::ostream& out, const Fixed& fixed);

#endif