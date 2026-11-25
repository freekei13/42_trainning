#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("DefaultAForm"), _signed(false), 
    _gradeReqSign(150), _gradeReqExec(150) {}

AForm::AForm(AForm const& src):
    _name(src._name), _signed(src._signed),
    _gradeReqSign(src._gradeReqSign),
    _gradeReqExec(src._gradeReqExec) {}

AForm::~AForm() {}

AForm&   AForm::operator=(AForm const& rhs)
{
    if (this != &rhs)
        _signed = rhs._signed;
    return *this;
}

AForm::AForm(std::string const& name, int gradeSign, int gradeExec):
    _name(name), _signed(false),
    _gradeReqSign(gradeSign), _gradeReqExec(gradeExec)
{
    if (gradeSign < 1 || gradeExec < 1)
        throw   GradeTooHighException();
    else if (gradeSign > 150 || gradeExec > 150)
        throw   GradeTooLowException();
}

std::string const& AForm::getName() const { return _name; }

int AForm::getGradeToSign() const { return _gradeReqSign; }

int AForm::getGradeToExec() const { return _gradeReqExec; }

bool    AForm::isSigned() const { return _signed; }

void    AForm::beSigned(Bureaucrat const& src)
{
    if (src.getGrade() <= _gradeReqSign)
        _signed = true;
    else
        throw GradeTooLowException();
}

char const* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

char const* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

char const* AForm::FormNotSignException::what() const throw()
{
    return "Form is not signed";
}

std::ostream&   operator<<(std::ostream& os, AForm const& src)
{
    os << "AForm's name: " << src.getName() << '\n'
        << "AForm is signed: " << src.isSigned() << '\n'
        << "Grade require to sign: " << src.getGradeToSign()
        << "Grade require to execute: " << src.getGradeToExec();
    return os;
}