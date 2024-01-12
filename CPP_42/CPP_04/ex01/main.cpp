#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	 const Animal* j = new Dog();
	 const Animal* i = new Cat();
	
	 delete j;
	 delete i;
	
	 std::cout << "=======================================" << std::endl;

	 const int n = 20;
	 const Animal* m[n];
	
	 for(int i = 0;i < n;i++)
	 {
	 	if (i < 10)
	 	{
	 		m[i] = new Dog();
	 		m[i]->makeSound();
	 	}
	 	else
	 	{
	 		m[i] = new Cat();
	 		m[i]->makeSound();
	 	}
	 }
	 for(int i = 0;i < n;i++)
	 	delete m[i];
	 std::cout << "=======================================" << std::endl;
	
	// Cat basic;
	// {
	// Cat tmp = basic;
	// }
	//
	// const Animal* test[4] = {new Dog(), new Dog(), new Cat(), new Cat()};
	// for(int i = 0;i< 4;i++)
	// 	delete test[i];

	return (0);

}
