#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class Contact
{
    private:
        std::string firstN;
        std::string lastN;
        std::string nickN;
        std::string phoneN;
        std::string darkS;
    public:
        void    setFirstN(std::string const &arg);
        void    setLastN(std::string const &arg);
        void    setNickN(std::string const &arg);
        void    setPhoneN(std::string const &arg);
        void    setDarkS(std::string const &arg);
        std::string getFirstN() const;
        std::string getLastN() const;
        std::string getNickN() const;
        std::string getPhoneN() const;
        std::string getDarkS() const;
};

#endif