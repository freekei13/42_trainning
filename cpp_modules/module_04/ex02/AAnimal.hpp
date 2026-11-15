#ifndef AAnimal_HPP
# define AAnimal_HPP

# include <iostream>
# include <string>

class AAnimal
{
    protected:
        std::string _type;
    public:
        AAnimal(void);
        AAnimal(AAnimal const& src);
        virtual ~AAnimal(void);

        AAnimal& operator=(AAnimal const& rhs);
        std::string    getType(void) const;
        virtual void   makeSound(void) const = 0;
};

#endif