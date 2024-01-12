#include "easyfind.hpp"

int main()
{
	std::vector<int> test(5, 7);
	test.push_back(5);
	test.push_back(75);
	test.push_back(4664);
	test.push_back(0);
	test.push_back(98);
	test.push_back(102);
	test.push_back(2354514);
	easyfind(test, 102);
}

