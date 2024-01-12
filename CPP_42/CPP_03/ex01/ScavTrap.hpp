#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP 

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap 
{
    public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &p);
    ScavTrap &operator=(const ScavTrap &p);
    ~ScavTrap();

    void guardGate();
};

#endif
