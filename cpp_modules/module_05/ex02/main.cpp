#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	Bureaucrat jim("Jim", 130);
	AForm* a = new ShrubberyCreationForm("home");
	jim.signAForm(*a);
	try
	{
		a->execute(jim);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	return 0;
}