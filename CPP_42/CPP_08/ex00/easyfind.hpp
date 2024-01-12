#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>

template<typename T>
void easyfind(T &vector, int nb)
{
	for(int i=0;i<vector.size();i++)
	{
		if (std::find(vector.begin(), vector.end(), nb) != vector.end())
		{
			std::cout << nb << std::endl;			
			return ;
		}
	}	
	std::cerr << "Error" << std::endl;
}	

#endif
