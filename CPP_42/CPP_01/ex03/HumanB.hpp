#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public:
	HumanB(std::string name);
	~HumanB();
	void	setWeapon(Weapon weapon);
	void	attack() const;

	private:
	std::string m_name;
	Weapon *m_weapon;
};

#endif