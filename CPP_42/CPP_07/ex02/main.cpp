#include "Array.hpp"

int main()
{
	Array<int> numbers(50);
	Array<int> numbers1(10);

	std::cout << "==========INT==========" << std::endl;
	for(int i = 0; i < 50;i++)
	{
		numbers[i] = 1;
	}
	numbers.print();
	
	std::cout << "----------" << std::endl;
	
	srand(time(NULL));
	for(int i = 0;i < 5; i++)
	{
		int a = rand();
		numbers1[i] = a;
	}
	numbers1.print();

	std::cout << "==========Char==========" << std::endl;
	
	Array<char> chara(50);
	Array<char> chara1(10);
	
	const char *tab = "My name is Hank!";
	const char *tab1 = "Hellllooo";
	for(int i = 0;i < 16;i++)
	{
		chara[i] = tab[i];
	}
	chara.print();

	std::cout << "----------" << std::endl;
	
	for(int i = 0;i < 5;i++)
	{
		chara1[i] = tab1[i];
	}
	chara1.print();
}
