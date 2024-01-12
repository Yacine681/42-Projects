#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	PmergeMe PmergeMe;

	if (argc == 1)
	{
		std::cout << "Error: Program need Arguments!" << std::endl;
		exit(0);
	}
	
	for(int i=1;argv[i];i++)
	{
		if (PmergeMe.checkError(argv[i]))
		{
			std::cout << "Error" << std::endl;
			exit(0);
		}
	}

	PmergeMe.insertValue(argv);
	PmergeMe.sortValue(argc);
}
