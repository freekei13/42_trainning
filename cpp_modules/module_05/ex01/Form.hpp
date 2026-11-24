#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>

class   Bureaucrat;

class   Form
{
    private:
        std::string const   _name;
        bool                _signed;
        int const           _gradeReqSign;
        int const           _gradeReqExec;
    public:
        Form();
        Form(Form const& src);
        ~Form();
        Form&   operator=(Form const& rhs);

        Form(std::string const& name, int gradeSign, int gradeExec);
        std::string const&  getName() const;
        int getGradeToSign() const;
        int getGradeToExec() const;
        bool    isSigned() const;
        void    beSigned(Bureaucrat const& src);

        class   GradeTooLowException: public std::exception
        {
            public:
                virtual char const* what() const throw();
        };

        class   GradeTooHighException: public std::exception
        {
            public:
                virtual char const* what() const throw();
        };
};

std::ostream&   operator<<(std::ostream& os, Form const& src);

#endif