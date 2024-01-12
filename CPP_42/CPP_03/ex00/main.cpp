#include "ClapTrap.hpp"

int main()
{   
    ClapTrap i;
        
    i.attack("Player2");
    i.takeDamage(7);
    i.beRepaired(5);
    i.attack("Player1");
    i.takeDamage(5);
    i.attack("Player2");
    i.takeDamage(5000);
}
