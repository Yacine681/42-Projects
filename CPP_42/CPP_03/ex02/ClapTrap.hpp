#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {

    protected:
    std::string trap;
    std::string m_name;
    int m_hitPoints;
    int m_energyPoints;
    int m_attackDamage;

    public:
    ClapTrap();
    ClapTrap(std::string name);
     ~ClapTrap();
    ClapTrap(const ClapTrap &p);
    ClapTrap &operator=(const ClapTrap &p); 
    void    attack(const std::string &target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);
};

#endif
