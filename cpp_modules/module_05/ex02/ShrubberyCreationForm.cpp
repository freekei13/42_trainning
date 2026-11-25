#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

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
    std::ofstream   file(_target.append("_shrubbery").c_str());
    if (!file.is_open())
        throw   FileFailOpenException();
    file << "      /### ####\\      \n"
        << "    /###### ####\\     \n"
        << "   |#### ##### ##|     \n"
        << "    \\### ######/      \n"
        << "         |  |          \n"
        << "         |{o|          \n"
        << "         |  |          \n"
        << "..,,,.../ || \\....,,,.\n";
    file.close();
    if (file.fail())
        throw FileFailWriteException();
}

char const* ShrubberyCreationForm::FileFailOpenException::what() const throw()
{
    return  "Error: file failed to open";
}

char const* ShrubberyCreationForm::FileFailWriteException::what() const throw()
{
    return  "Error: file failed to write";
}