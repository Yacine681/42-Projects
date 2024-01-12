#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &p)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    m_type = p.m_type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &p)
{
    std::cout << "WrongAnimal copy assignement operator called" << std::endl;
    m_type = p.m_type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal default destructor called" << std::endl;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "Animal sound!" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (m_type);
}
