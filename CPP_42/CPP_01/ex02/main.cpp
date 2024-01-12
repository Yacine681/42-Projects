#include <string>
#include <iostream>

int main(void)
{
	std::string Brain = "HI THIS IS BRAIN";
	std::string *stringPtr = &Brain;
	std::string &stringREF = Brain;

	std::cout << &Brain << std::endl;
	std::cout << stringPtr << std::endl;
	std::cout << &stringREF << std::endl;
}