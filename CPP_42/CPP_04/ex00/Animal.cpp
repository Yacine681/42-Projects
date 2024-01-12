#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &p)
{   
    std::cout << "Animal copy constructor called" << std::endl;
    m_type = p.m_type;    
}

Animal &Animal::operator=(const Animal &p)
{
    std::cout << "Animal copy assignement operator called" << std::endl;
    m_type = p.m_type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal default destructor called" << std::endl;
}

void Animal::makeSound(void) const
{
    std::cout << "Animal sound!" << std::endl; 
}

std::string Animal::getType() const 
{
    return (m_type);
}

