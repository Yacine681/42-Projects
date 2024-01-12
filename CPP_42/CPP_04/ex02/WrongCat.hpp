#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal
{
    public:
    WrongCat();
    WrongCat(const WrongCat &p);
    WrongCat &operator=(const WrongCat &p);
    ~WrongCat();

    void makeSound() const;
};

#endif
