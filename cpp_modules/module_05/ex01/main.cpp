#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat	pat("Pat", 30);
	std::cout << pat << std::endl;
	Bureaucrat	jim("Jim", 5);
	std::cout << jim << std::endl;

	try
	{
		Form	StockForm("Stock form", 10, 10);
		std::cout << StockForm << std::endl;
		jim.signForm(StockForm);
		std::cout << StockForm << std::endl;
		pat.signForm(StockForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		Form	nonValidForm("NonValide", 0, 150);
		std::cout << nonValidForm << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	return 0;
}