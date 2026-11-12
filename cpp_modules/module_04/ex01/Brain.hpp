#ifndef Brain_HPP
# define Brain_HPP

#include <string>
#include <iostream>

class Brain
{
    private:
        std::string _ideas[100];
    public:
        Brain(void);
        Brain(Brain const& src);
        ~Brain(void);

        Brain& operator=(Brain const& rhs);
};

#endif