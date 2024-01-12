#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    std::cout << "===================================================" << std::endl;

    const WrongAnimal* Animal = new WrongAnimal();
    const WrongAnimal* Cat = new WrongCat();

    Animal->getType();
    Cat->getType();
    Animal->makeSound();
    Cat->makeSound();

    delete Animal;
    delete Cat;

    return (0);
}
