#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {

    private:
    std::string m_name;

    public:
    Zombie();
    Zombie(std::string name);
	~Zombie();

    void    announce(void) const;
    void    name(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
