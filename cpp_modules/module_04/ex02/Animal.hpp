#ifndef Animal_HPP
# define Animal_HPP

# include <iostream>
# include <string>

class Animal
{
    protected:
        std::string _type;
    public:
        Animal(void);
        Animal(Animal const& src);
        virtual ~Animal(void);

        Animal& operator=(Animal const& rhs);
        std::string    getType(void) const;
        virtual void   makeSound(void) const = 0;
};

#endif