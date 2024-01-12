#include "FragTrap.hpp"

int main()
{   
    FragTrap i;

    //FragTrap("Player1");
    //FragTrap("Player2");
        
    i.attack("Player2");
    i.takeDamage(40);
    i.beRepaired(5);
    i.attack("Player1");
    i.takeDamage(5);
    i.attack("Player2");
    i.highFivesGuys();
    i.takeDamage(5000);
}
