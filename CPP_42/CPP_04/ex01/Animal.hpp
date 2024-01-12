#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal {

    protected:
    std::string m_type;

    public:
    Animal();
    Animal(const Animal &p);
    Animal &operator=(const Animal &p);
    virtual ~Animal();

    virtual void makeSound(void) const;
    std::string getType() const;
};

#endif
