#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat test("Pat", 150);
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}