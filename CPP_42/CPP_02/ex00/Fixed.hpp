#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

    private:
    int m_fixe;
    static int const m_bits = 8;

    public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed &p);
    Fixed &operator=(const Fixed &p);
    int getRawBits(void) const;
    void    setRawBits(int const raw);

};

#endif
