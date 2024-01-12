#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat test("hello", 1);
		std::cout << test << std::endl;
		test.incremente();	
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}
