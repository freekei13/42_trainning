#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"

class   ShrubberyCreationForm: public AForm
{
    private:
        std::string _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm const& src);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm&  operator=(ShrubberyCreationForm const& rhs);

        ShrubberyCreationForm(std::string const& target);
        void    execute(Bureaucrat const& executor) const;

        class   FileFailOpenException: public std::exception
        {
            public:
                virtual char const* what() const throw();
        };

        class   FileFailWriteException: public std::exception
        {
            public:
                virtual char const* what() const throw();
        };
};

#endif