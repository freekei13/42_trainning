#ifndef Dog_HPP
# define Dog_HPP

#include "Animal.hpp"

class Dog: public Animal
{
    public:
        Dog(void);
        Dog(Dog const& src);
        ~Dog(void);

        Dog&    operator=(Dog const& rhs);
        void    makeSound() const;
};

#endif