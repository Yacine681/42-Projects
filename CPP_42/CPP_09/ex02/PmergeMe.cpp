#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	// std::cout << "Constructor called!" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &p)
{
	// std::cout << "Copy constructor called!" << std::endl;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &p)
{
	// std::cout << "Copy assignement operator called!" << std::endl;
	return *this;
}

PmergeMe::~PmergeMe()
{
 	// std::cout << "Destructor called!" << std::endl;
}

void PmergeMe::insertValue(char **argv)
{
	// Vector
	for(int i=1;argv[i];i++)
		vector.push_back(atoi(argv[i]));
	
	// Deque
	for(int i=1;argv[i];i++)
		deque.push_back(atoi(argv[i]));
}

int PmergeMe::checkError(std::string argv)
{
	for(int i=0;argv[i];i++)
	{
		if (isdigit(argv[i]) == false)
			return (-1);
	}
	return(0);
}

void PmergeMe::sortValue(int argc)
{
	std::cout << "Before: ";
	for(int i=0;i<vector.size();i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;

	std::clock_t start1 = std::clock();
	std::sort(vector.begin(), vector.end());
	std::clock_t end1 = std::clock();

	std::clock_t start2 = std::clock();
	std::sort(deque.begin(), deque.end());
	std::clock_t end2 = std::clock();
	
	double vector_us = double(end1 - start1) / CLOCKS_PER_SEC * 1000;
	double deque_us = double(end2 - start2) / CLOCKS_PER_SEC * 1000;

	std::cout << "After:  ";
	for(int i=0;i<vector.size();i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << std::setprecision(5) << vector_us << " us";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << std::setprecision(5) << deque_us << " us";
	std::cout << std::endl;
}
