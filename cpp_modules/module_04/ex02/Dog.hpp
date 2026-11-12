#ifndef Dog_HPP
# define Dog_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
    private:
        Brain* _brain;
    public:
        Dog(void);
        Dog(Dog const& src);
        ~Dog(void);

        Dog&    operator=(Dog const& rhs);
        void    makeSound() const;
        const std::string&  getIdea(unsigned int index) const;
        void    setIdea(unsigned int index, std::string const& idea);
};

#endif