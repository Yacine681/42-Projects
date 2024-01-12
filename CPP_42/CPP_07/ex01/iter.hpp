#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T>
void iter(const T tab[], const int size, void (*function)(const T &number))
{
	for(int i = 0;i < size; i++)
	{
		function(tab[i]);
	}
}

template<typename T>
void function(T const &number) {
	std::cout << number << std::endl;
}

#endif
