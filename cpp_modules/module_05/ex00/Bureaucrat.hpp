#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class   Bureaucrat
{
    private:
        std::string const   _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(Bureaucrat const& src);
        ~Bureaucrat();
        Bureaucrat& operator=(Bureaucrat const& rhs);

        Bureaucrat(std::string const& name, int grade);
        std::string const&  getName() const;
        int getGrade() const;
        void    getPromote();
        void    getDemote();
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& src);

#endif