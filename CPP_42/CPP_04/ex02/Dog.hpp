#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{
	private:
    Brain *m_brain;

    public:
    Dog();
    Dog(const Dog &p);
    Dog &operator=(const Dog &p);
    ~Dog();
    
    void makeSound(void) const;
};

#endif
