#include "Zombie.hpp"

int main(void)
{
    int i = 0;
    Zombie *str = zombieHorde(10, "Zombi");

    while(i != 10)
    {
        str[i].announce();
        i++;
    }
    delete[] str;
    return (0);
}
