#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

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

void    RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    if (!this->isSigned())
        throw FormNotSignException();
    if (executor.getGrade() > this->getGradeToExec())
        throw GradeTooLowException();
    int roll = rand() % 100 + 1;
    std::cout << "Roll: " << roll << std::endl;
    std::cout << "*..Drilling noises..*" << std::endl;
    if (roll > 50)
        std::cout << _target << " has been robotomized." << std::endl;
    else
        std::cout << _target << " has failed to robotomy." << std::endl;
}