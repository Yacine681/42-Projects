#include "Zombie.hpp"

void    randomChump(std::string name)
{
    Zombie zombar = Zombie(name);
    zombar.announce();
}
