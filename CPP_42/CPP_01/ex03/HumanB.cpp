#include "HumanB.hpp"

HumanB::HumanB(std::string name) : m_name(name), m_weapon(NULL)
{}

HumanB::~HumanB()
{}

void	HumanB::setWeapon(Weapon weapon)
{
	m_weapon = &weapon;
}

void	HumanB::attack() const
{
	if (m_weapon)
		std::cout << m_name << " attacks with their " << m_weapon->get_type() << std::endl;
	else
		std::cout << m_name << " attacks with their " << std::endl;
}