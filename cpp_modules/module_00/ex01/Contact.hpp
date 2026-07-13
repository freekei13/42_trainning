#ifndef CONTACT_HPP
# define CONTACT_HPP
# include "main.hpp"

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkSecret;
    public:
        void    setFirstName(const std::string argument);
        void    setLastName(const std::string argument);
        void    setNickName(const std::string argument);
        void    setPhoneNumber(const std::string argument);
        void    setSecret(const std::string argument);
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickName() const;
        std::string getPhoneNumber() const;
        std::string getSecret() const;
};

#endif
