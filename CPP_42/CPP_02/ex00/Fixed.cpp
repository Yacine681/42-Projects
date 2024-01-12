#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	m_fixe = 0; 
}

Fixed::Fixed(const Fixed &p)
{
	std::cout << "Copy constructor called" << std::endl;
	m_fixe = p.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &p)
{
	std::cout << "Copy assignment operator called" << std::endl;
	m_fixe = p.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(m_fixe);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	m_fixe = raw;
}
