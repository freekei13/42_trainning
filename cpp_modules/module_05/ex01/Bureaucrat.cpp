#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(): _name("none"), _grade(150) {}

Bureaucrat::Bureaucrat(Bureaucrat const& src):
    _name(src._name), _grade(src._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs) 
{
    if (this != &rhs)
        _grade = rhs._grade;
    return *this;
}

Bureaucrat::Bureaucrat(std::string const& name, int grade): _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    else
        _grade = grade;
}

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
    else
        throw GradeTooHighException();
}

void    Bureaucrat::getDemote()
{
    if (_grade < 150)
        _grade++;
    else
        throw GradeTooLowException();
}

void    Bureaucrat::signForm(Form& src)
{
    try
    {
        src.beSigned(*this);
        std::cout << _name << " signed " << src.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << _name << " couldn't sign " << src.getName();
        std::cerr << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

std::ostream&   operator<<(std::ostream& os, Bureaucrat const& src)
{
    os << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
    return os;
}