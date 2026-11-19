#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("none"), _grade(150) {}

Bureaucrat::Bureaucrat(Bureaucrat const& src):
    _name(src._name), _grade(src._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs) {}

Bureaucrat::Bureaucrat(std::string const& name, int grade):
    _name(name), _grade(grade)
{
    
}
