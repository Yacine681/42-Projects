#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	int i = 0;
	Zombie *ptr = new Zombie[N];

	while(i != N)
	{
		ptr[i].name(name);
		i++; 
	}
	return (ptr);
}