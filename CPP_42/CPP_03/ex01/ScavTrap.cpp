#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    m_name = "Player1";
    m_hitPoints = 100;
    m_energyPoints = 50;
    m_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap std::string constructor called" << std::endl;
    m_name = name;
    m_hitPoints = 100;
    m_energyPoints = 50;
    m_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &p)
{
	std::cout << "Copy constructor called" << std::endl;
    m_name = p.m_name;
    m_hitPoints = p.m_hitPoints;
    m_energyPoints = p.m_energyPoints;
    m_attackDamage = p.m_attackDamage;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &p)
{
    m_name = p.m_name;
    m_hitPoints = p.m_hitPoints;
    m_energyPoints = p.m_energyPoints;
    m_attackDamage = p.m_attackDamage;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "GuardGate!" << std::endl;
}
