#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("DefaultForm"), _signed(false), 
    _gradeReqSign(150), _gradeReqExec(150) {}

Form::Form(Form const& src):
    _name(src._name), _signed(src._signed),
    _gradeReqSign(src._gradeReqSign),
    _gradeReqExec(src._gradeReqExec) {}

Form::~Form() {}

Form&   Form::operator=(Form const& rhs)
{
    if (this != &rhs)
        _signed = rhs._signed;
    return *this;
}

Form::Form(std::string const& name, int gradeSign, int gradeExec):
    _name(name), _signed(false),
    _gradeReqSign(gradeSign), _gradeReqExec(gradeExec)
{
    if (gradeSign < 1 || gradeExec < 1)
        throw   GradeTooHighException();
    else if (gradeSign > 150 || gradeExec > 150)
        throw   GradeTooLowException();
}

std::string const& Form::getName() const { return _name; }

int Form::getGradeToSign() const { return _gradeReqSign; }

int Form::getGradeToExec() const { return _gradeReqExec; }

bool    Form::isSigned() const { return _signed; }

void    Form::beSigned(Bureaucrat const& src)
{
    if (src.getGrade() <= _gradeReqSign)
        _signed = true;
    else
        throw GradeTooLowException();
}

char const* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

char const* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

std::ostream&   operator<<(std::ostream& os, Form const& src)
{
    os << "Form's name: " << src.getName() << '\n'
        << "Form is signed: " << src.isSigned() << '\n'
        << "Grade require to sign: " << src.getGradeToSign()
        << "Grade require to execute: " << src.getGradeToExec();
    return os;
}