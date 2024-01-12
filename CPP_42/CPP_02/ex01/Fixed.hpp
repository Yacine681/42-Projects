#ifndef FIXED_HPP
# define FIXED_HPP


#include <iostream>

class Fixed {

    private:
    int m_fixe;
    const static int m_bits = 8;

    public:
	Fixed();
    Fixed(const Fixed &p);
    Fixed &operator=(const Fixed &p);
    ~Fixed();
    
    Fixed(int const fixe);
    Fixed(float const fixe);

	int getRawBits(void) const;
    void setRawBits(int const raw);
	float 	toFloat(void) const;
	int 	toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, Fixed const &obj);

#endif
