#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): 
    AForm("ShrubberyCreationForm", 145, 137),
    _target("none") {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src): 
    AForm(src), _target(src._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target):
    AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

void    ShrubberyCreationForm::execute(Bureaucrat const& executor)
{
    if (!this->isSigned())
        throw   FormNotSignException();
    else if (executor.getGrade() > this->getGradeToExec())
        throw   GradeTooLowException();
    else
    {
        
    }
}