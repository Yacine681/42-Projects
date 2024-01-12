#include "Zombie.hpp"

Zombie::Zombie()
{}

Zombie::Zombie(std::string name)
{
    m_name = name;
}

Zombie::~Zombie()
{
    std::cout << m_name << ": DEATH" << std::endl;
}

void Zombie::announce(void) const
{
    std::cout << m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::name(std::string name)
{
    m_name = name;
}
