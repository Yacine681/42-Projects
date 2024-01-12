#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat default constructor called" << std::endl;
    m_brain = new Brain();
}

Cat::Cat(const Cat &p) : Animal()
{
    std::cout << " Cat copy constructor called" << std::endl;
	m_type = p.m_type;
	delete m_brain;
	m_brain = new Brain(*(p.m_brain));
}

Cat &Cat::operator=(const Cat &p)
{
    std::cout << "Cat copy assignement operator called" << std::endl;
	m_type = p.m_type;
	m_brain = new Brain(*(p.m_brain));
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
	delete m_brain;
}

void Cat::makeSound(void) const
{
    std::cout << "Meow!" << std::endl;
}
