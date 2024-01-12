#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon 
{
	public:
	Weapon(std::string type);
	~Weapon();
	std::string	get_type() const;
	void	setType(std::string type);

	private:
	std::string m_type;
};

#endif
