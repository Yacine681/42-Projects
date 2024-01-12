#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat default constructor called" << std::endl;
    m_type = "Cat";
}

Cat::Cat(const Cat &p) : Animal()
{
    std::cout << " Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &p)
{
    std::cout << "Cat copy assignement operator called" << std::endl;
    m_type = p.m_type;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << "Meow!" << std::endl;
}
