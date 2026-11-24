#include "Form.hpp"

Form::Form(): _name("none"), _signed(false), 
    _gradeReqSign(0), _gradeReqExec(0) {}

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
        throw   Form::GradeTooHighException();
    else if (gradeSign > 150 || gradeExec > 150)
        throw   Form::GradeTooLowException();
}

std::string const& Form::getName() const { return _name; }

int Form::getGradeToSign() const { return _gradeReqSign; }

int Form::getGradeToExec() const { return _gradeReqExec; }

bool    Form::isSigned() const { return _signed; }

void    Form::beSigned(Bureaucrat const& src)
{

}