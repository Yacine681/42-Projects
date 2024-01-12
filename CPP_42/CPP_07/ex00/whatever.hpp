#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template<typename T>
void swap(T& a, T& b)
{
	T tmp_a;

	tmp_a = a;
	a = b;
	b = tmp_a;
}

template<typename T>
T min(T& a, T& b)
{
	if (a < b)
		return (a);
	else if (b < a)
		return (b);
	else
		return (b);
}

template<typename T>
T max(T& a, T& b)
{
	if (a < b)
		return (b);
	else if (b < a)
		return (a);
	else
		return (b);
}

#endif
