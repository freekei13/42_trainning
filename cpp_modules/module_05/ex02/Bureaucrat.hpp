#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <ostream>
# include <exception>

class   AForm;

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
        void    signForm(AForm& src);
        void    executeForm(AForm const& src) const;
        
        class   GradeTooHighException: public std::exception
        {
            virtual const char*  what() const throw();
        };

        class   GradeTooLowException: public std::exception
        {
            virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& src);

#endif