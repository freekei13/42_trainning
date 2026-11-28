#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(): 
    AForm("PresidentialPardonForm", 25, 5),
    _target("none") {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src):
    AForm(src), _target(src._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return *this;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target):
    AForm("PresidentialPardonForm", 25, 5),
    _target(target) {}

void    PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    if (!this->isSigned())
        throw FormNotSignException();
    if (executor.getGrade() > this->getGradeToExec())
        throw GradeTooLowException();
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}