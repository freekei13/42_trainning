#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():
    AForm("RobotomyRequestForm", 72, 45),
    _target("none") {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src):
    AForm(src), _target(src._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&    RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target):
    AForm("RobotomyRequestForm", 72, 45),
    _target(target) {}

void    RobotomyRequestForm::execute(Bureaucrat const& executor)
{

}

char const* RobotomyRequestForm::RobotomyFailException::what() const throw()
{
    return "Robotomy failed!";
}