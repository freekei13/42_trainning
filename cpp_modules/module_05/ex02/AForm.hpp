#ifndef AForm_HPP
# define AForm_HPP

# include <string>
# include <iostream>
# include <ostream>
# include <exception>

class   Bureaucrat;

class   AForm
{
    private:
        std::string const   _name;
        bool                _signed;
        int const           _gradeReqSign;
        int const           _gradeReqExec;
    public:
        AForm();
        AForm(AForm const& src);
        ~AForm();
        AForm&   operator=(AForm const& rhs);

        AForm(std::string const& name, int gradeSign, int gradeExec);
        std::string const&  getName() const;
        int getGradeToSign() const;
        int getGradeToExec() const;
        bool    isSigned() const;
        void    beSigned(Bureaucrat const& src);
        virtual void    execute(Bureaucrat const& executor) const = 0;

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

        class   FormNotSignException: public std::exception
        {
            public:
                virtual char const* what() const throw();
        };
};

std::ostream&   operator<<(std::ostream& os, AForm const& src);

#endif