#include "ScavTrap.hpp"

int main()
{   
    ScavTrap i;

    ScavTrap("Player1");
    ScavTrap("Player2");
        
    i.attack("Player2");
    i.takeDamage(40);
    i.beRepaired(5);
    i.attack("Player1");
    i.takeDamage(5);
    i.attack("Player2");
    i.guardGate();
    i.takeDamage(5000);
}
