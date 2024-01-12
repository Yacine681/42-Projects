#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    m_name = "Player1";
    m_hitPoints = 100;
    m_energyPoints = 100;
    m_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap std::string constructor called" << std::endl;
    m_name = name;
    m_hitPoints = 100;
    m_energyPoints = 100;
    m_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &p)
{
	std::cout << "Copy constructor called" << std::endl;
    m_name = p.m_name;
    m_hitPoints = p.m_hitPoints;
    m_energyPoints = p.m_energyPoints;
    m_attackDamage = p.m_attackDamage;
}

FragTrap &FragTrap::operator=(const FragTrap &p)
{
    m_name = p.m_name;
    m_hitPoints = p.m_hitPoints;
    m_energyPoints = p.m_energyPoints;
    m_attackDamage = p.m_attackDamage;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "HighFivesGuys!" << std::endl;
}
