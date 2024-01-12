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

    bool	operator>(Fixed src_) const;
	bool	operator<(Fixed src_) const;
	bool	operator>=(Fixed src_) const;
	bool	operator<=(Fixed src_) const;
	bool	operator==(Fixed src_) const;
	bool	operator!=(Fixed src_) const;
	Fixed	operator+(Fixed src_) const;
	Fixed	operator-(Fixed src_) const;
	Fixed	operator*(Fixed src_) const;
	Fixed	operator/(Fixed src_) const;
	Fixed	operator++(int);
	Fixed	operator++(void);
	Fixed	operator--(int);
	Fixed	operator--(void);
	static Fixed	&min(Fixed &n1, Fixed &n2);
	static const Fixed	&min(const Fixed &n1, const Fixed &n2);
	static Fixed	&max(Fixed &n1, Fixed &n2);
	 static const Fixed	&max(const Fixed &n1, const Fixed &n2);
};

std::ostream &operator<<(std::ostream &os, Fixed const &obj);

#endif
