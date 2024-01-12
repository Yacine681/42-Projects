#include "Base.hpp"

int main(void)
{
	Base *test1 = generate();

	std::cout << "test 1 with pointer = ";
	identify(test1);
	std::cout << "test 1 with reference = ";
	identify(*test1);
}
