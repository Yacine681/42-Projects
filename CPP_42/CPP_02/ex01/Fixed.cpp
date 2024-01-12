#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->m_fixe = 0; 
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

Fixed::Fixed(int const fixe)
{
    std::cout << "Int constructor called" << std::endl;
	this->m_fixe = fixe << m_bits;
}

Fixed::Fixed(float const fixe)
{
    std::cout << "Float constructor called" << std::endl;
	float pre = 1 << m_bits;
    this->m_fixe = roundf(fixe * pre);
}

int Fixed::getRawBits(void) const
{
	return(m_fixe);
}

void Fixed::setRawBits(int const raw)
{
	m_fixe = raw;
}

int Fixed::toInt(void) const {
    return (m_fixe >> m_bits);
}

float Fixed::toFloat(void) const {
    float prec = 1 << m_bits;
    float nb;
    nb = (float)m_fixe / prec;
    return (nb);
}

std::ostream &operator<<(std::ostream &os, Fixed const &obj)
{
	return (os << obj.toFloat());
}
