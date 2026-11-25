#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"

class   RobotomyRequestForm: public AForm
{
    private:
        std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(RobotomyRequestForm const& src);
        ~RobotomyRequestForm();
        RobotomyRequestForm&    operator=(RobotomyRequestForm const& rhs);

        RobotomyRequestForm(std::string const& target);
        void    execute(Bureaucrat const& executor);

        class   RobotomyFailException: public std::exception
        {
            virtual char const* what() const throw();
        };
};

#endif