#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog default constructor called" << std::endl;
    m_type = "Dog";
}

Dog::Dog(const Dog &p) : Animal()
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &p)
{
    std::cout << "Dog copy assignement operator called" << std::endl;
    m_type = p.m_type;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << "Waouf!" << std::endl;
}
