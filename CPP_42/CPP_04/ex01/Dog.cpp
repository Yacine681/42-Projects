#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog default constructor called" << std::endl;
    m_brain = new Brain();
}

Dog::Dog(const Dog &p) : Animal()
{
    std::cout << "Dog copy constructor called" << std::endl;
	m_type = p.m_type;
	delete m_brain;
	m_brain = new Brain(*(p.m_brain));
}

Dog &Dog::operator=(const Dog &p)
{
    std::cout << "Dog copy assignement operator called" << std::endl;
	m_type = p.m_type;
	m_brain = new Brain(*(p.m_brain));
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
	delete m_brain;
}

void Dog::makeSound(void) const
{
    std::cout << "Waouf!" << std::endl;
}
