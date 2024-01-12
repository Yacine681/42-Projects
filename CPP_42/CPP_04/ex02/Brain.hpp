#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain 
{
    private:
    std::string m_ideas[100];

    public:
    Brain();
    Brain(const Brain &p);
    Brain& operator=(const Brain &p);
	~Brain();
};

#endif
