#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{
    public:
    Cat();
    Cat(const Cat &p);
    Cat &operator=(const Cat &p);
    ~Cat();

    void makeSound() const;
};

#endif
