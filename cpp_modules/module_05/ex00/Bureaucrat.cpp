#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("none"), _grade(150) {}

Bureaucrat::Bureaucrat(Bureaucrat const& src):
    _name(src._name), _grade(src._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs) {}

Bureaucrat::Bureaucrat(std::string const& name, int grade):
    _name(name), _grade(grade) {}

std::string const&  Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void    Bureaucrat::getPromote()
{
    if (_grade > 1)
        _grade--;
}

void    Bureaucrat::getDemote()
{
    if (_grade < 150)
        _grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too hight";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

std::ostream&   operator<<(std::ostream& os, Bureaucrat const& src)
{
    std::ostream    out;

}