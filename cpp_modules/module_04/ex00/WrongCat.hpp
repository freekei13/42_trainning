#ifndef WrongCat_HPP
# define WrongCat_HPP

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
    public:
        WrongCat(void);
        WrongCat(WrongCat const& src);
        ~WrongCat(void);

        WrongCat&    operator=(WrongCat const& rhs);
        void    makeSound(void) const;
};

#endif