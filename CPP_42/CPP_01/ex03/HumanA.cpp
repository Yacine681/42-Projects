#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon) : m_weapon(weapon), m_name(name)
{}

HumanA::~HumanA()
{}

void	HumanA::attack() const
{
	std::cout << m_name << " attacks with their " << m_weapon.get_type() << std::endl;
}