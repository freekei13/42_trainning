#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <time.h>

int	main()
{
	srand(time(NULL));
	Bureaucrat jim("Jim", 130);
	Bureaucrat pat("Pat", 1);
	AForm* a = new ShrubberyCreationForm("home");
	AForm* b = new RobotomyRequestForm("dog");
	AForm* c = new PresidentialPardonForm("Wife");
	jim.signForm(*a);
	jim.signForm(*b);
	jim.signForm(*c);
	jim.executeForm(*a);
	jim.executeForm(*b);
	jim.executeForm(*c);
	std::cout << std::endl;

	pat.signForm(*b);
	pat.signForm(*c);
	pat.executeForm(*b);
	pat.executeForm(*c);

	return 0;
}