#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		exit(EXIT_FAILURE);
	}
	
	Bitcoin Bitcoin;

	Bitcoin.DataBase("data.csv");
	Bitcoin.Input(argv[1]);
	return (0);	
}
