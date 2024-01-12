#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected:
    std::string m_type;

    public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &p);
    WrongAnimal &operator=(const WrongAnimal &p);
    virtual ~WrongAnimal();

    void makeSound() const;
    std::string getType() const;
    
};

#endif
