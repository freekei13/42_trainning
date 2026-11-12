#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP
# include <iostream>
# include <string>

class WrongAnimal
{
    protected:
        std::string _type;
    public:
        WrongAnimal(void);
        WrongAnimal(WrongAnimal const& src);
        ~WrongAnimal(void);

        WrongAnimal& operator=(WrongAnimal const& rhs);
        std::string    getType(void) const;
        void   makeSound(void) const;
};

#endif