#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "WrongCat default constructor called" << std::endl;
    m_type = "Cat";
}

WrongCat::WrongCat(const WrongCat &p) : WrongAnimal()
{
    std::cout << " Cat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &p)
{
    std::cout << "WrongCat copy assignement operator called" << std::endl;
    m_type = p.m_type;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound(void) const
{
    std::cout << "Meow!" << std::endl;
}
