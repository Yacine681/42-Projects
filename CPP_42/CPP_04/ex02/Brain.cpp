#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	for(int i = 0;i < 100;i++)
		m_ideas[i] = "";
}

Brain::Brain(const Brain &p)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for(int i = 0;i < 100;i++)
		m_ideas[i] = p.m_ideas[i];
}

Brain &Brain::operator=(const Brain &p)
{
	std::cout << "Brain copy assignement operator called" << std::endl;
	if (this != &p)
	{
		for(int i = 0;i < 100;i++)
			this->m_ideas[i] = p.m_ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}
