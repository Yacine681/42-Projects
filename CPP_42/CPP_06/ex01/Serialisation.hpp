#ifndef SERIALISATION_HPP
# define SERIALISATION_HPP

#include <iostream>

struct Data {
	std::string name;
	const char *sexe;
	int age;
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif 
