#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat pat("Pat", 150);
		std::cout << pat << std::endl;
		pat.getDemote();
		std::cout << pat << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat sam("Sam", -1);
		std::cout << sam << std::endl;
		sam.getPromote();
		std::cout << sam << std::endl;
		Bureaucrat lin("Lin", 1);
		std::cout << lin << std::endl;
		lin.getPromote();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
	return 0;
}