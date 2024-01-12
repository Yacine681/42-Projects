#include "iter.hpp"

int main()
{
	std::cout << "==========TAB CHAR==========" << std::endl;
	char tab1[] = "Hello World!";
	iter(tab1, 12, function<char>);

	std::cout << "----------" << std::endl;

	char tab2[] = "Test_123456";
	iter(tab2, 5, function<char>);

	std::cout << "==========TAB INT==========" << std::endl;
	int tab3[] = {1, 2, 3, 4, 5, 6, 7 ,8 , 9};
	iter(tab3, 9, function<int>);
	
	std::cout << "----------" << std::endl;

	int tab4[] = {42, 42, 42, 42, 42, 42};
	iter(tab4, 3, function<int>);

}
