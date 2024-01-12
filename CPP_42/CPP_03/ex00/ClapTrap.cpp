#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{  
    m_name = "Player1";
    std::cout << "Default constructor called" << std::endl;
    m_hitPoints = 10;
    m_energyPoints = 10;
    m_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "std::string Default constructor called" << std::endl;
    m_name = name;
    m_hitPoints = 10;
    m_energyPoints = 10;
    m_attackDamage = 0;    
}

ClapTrap::ClapTrap(const ClapTrap &p)
{
	std::cout << "Copy constructor called" << std::endl;
    m_name = p.m_name;
    m_hitPoints = p.m_hitPoints;
    m_energyPoints = p.m_energyPoints;
    m_attackDamage = p.m_attackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &p)
{
    m_name = p.m_name;
    m_hitPoints = p.m_hitPoints;
    m_energyPoints = p.m_energyPoints;
    m_attackDamage = p.m_attackDamage;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{  
    if (m_energyPoints && m_hitPoints)
    {
         std::cout << "ClapTrap " << m_name << " attacks " << target << ", causing " << m_attackDamage << " points of damage" << std::endl;
         m_energyPoints--;
    }
    else
        std::cout << "nothing energyPoints" << std::endl;
    m_name = target;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (!m_energyPoints || !m_hitPoints)
        return ;
    std::cout << "ClapTrap " << m_name << " a receipt " << amount << " points of damage" << std::endl;
    m_hitPoints = m_hitPoints - amount;
    if (m_hitPoints <= 0)
    {   m_hitPoints = 0;
        std::cout << m_name <<  " is dead!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (m_energyPoints && m_hitPoints)
    {
        std::cout << "ClapTrap " << m_name << " a receipt " << amount << " points of heal" << std::endl;
        m_hitPoints += amount;
        m_energyPoints--;
    }
    else
        std::cout << "nothing energyPoints" << std::endl;
}

