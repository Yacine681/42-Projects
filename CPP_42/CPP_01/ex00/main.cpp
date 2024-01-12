#include "Zombie.hpp"

int main(void)
{
    Zombie zombir = Zombie("Zombir");
    zombir.announce();
    Zombie *zombat = newZombie("Zombat");
    zombat->announce();
    randomChump("Zombo");
    delete zombat;
}
