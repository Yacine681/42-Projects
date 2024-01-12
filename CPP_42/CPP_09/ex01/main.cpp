#include "Rpn.hpp"

int main(int argc, char **argv)
{
	Rpn Rpn;

	if (argc != 2)
	{
		std::cout << "Error Argument!" << std::endl;
		exit(0);
	}

	else if (Rpn.check_error(argv[1]))
	{
		std::cout << "Error" << std::endl;
		exit(0);
	}
	std::string rpn = argv[1];
	std::cout << Rpn.Calculate(rpn) << std::endl;
}
