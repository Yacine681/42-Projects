#include "Serialisation.hpp"

uintptr_t serialize(Data* ptr)
{
	uintptr_t t;

	t = reinterpret_cast<std::uintptr_t>(ptr);
	return (t);
}

Data* deserialize(uintptr_t raw)
{
	Data *data;

	data = reinterpret_cast<Data *>(raw);
	return (data);
}

int main(void)
{
	Data *i = new Data;
	
	i->name = "Hank";
	i->sexe = "Masculin";
	i->age = 20;

	std::cout << "=====================================" << std::endl;
	std::cout << "Name: " << i->name << std::endl;
	std::cout << "Sexe: " << i->sexe << std::endl;
	std::cout << "Age: " << i->age << std::endl;

	std::cout << "=====================================" << std::endl;
	std::cout << "Name: " << deserialize(serialize(i))->name << std::endl;
	std::cout << "Sexe: " << deserialize(serialize(i))->sexe << std::endl;
	std::cout << "Age: " << deserialize(serialize(i))->age << std::endl;
}
