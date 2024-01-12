#include "Convert.hpp"

int g_check_point = 0;

void check_point(char *argv)
{
	int i = 0;

	while(argv[i])
	{
		if(argv[i] == '.' && argv[i + 1] == '0')
		{
			g_check_point = 42;
			break ;
		}
		else if (argv[i] == '.') 
		{
			g_check_point++;
			break ;
		}
		i++;
	}
}

void ft_parse(char *argv)
{
	double ft_double;

	check_point(argv);
	if (argv[0] >= 'a' && argv[0] <= 'z' && argv[1] == '\0')
		ft_double = (double)argv[0]; 
	else
		ft_double = std::strtod(argv, NULL);
	
	if (ft_double == 0 && argv[0] != '0' && argv[1] != '\0')
	{
		std::cout << "Error Argument" << std::endl;
		return ;
	}

	toChar(argv[0], ft_double, argv);
	toInt(ft_double, argv);
	toFloat(ft_double, argv);
	toDouble(ft_double, argv);

}

void toChar(char const &ft_char, double ft_double, char *argv)
{	
	if (ft_check(argv) == 0)
		std::cout << "Char: Impossible" << std::endl;
	else if (ft_double < std::numeric_limits<char>::min() || ft_double > std::numeric_limits<char>::max())
		std::cout << "OVERFLOW" << std::endl;
	else if (ft_char >= 'a' && ft_char <= 'z')
		std::cout << "char: " << ft_char << std::endl;
	else
	{
		char c = ft_double;
		if (!c || c <= 32)
		{
			std::cout << "char: Non displayable" << std::endl;
			return ;
		}
		std::cout << "char: " << c << std::endl;
	}
}

void toInt(double const &ft_int, char *argv)
{
	if (ft_check(argv) == 0)
		std::cout << "Int: Impossible" << std::endl;
	else if (ft_int < std::numeric_limits<int>::min() || ft_int > std::numeric_limits<int>::max())
			std::cout << "OVERFLOW" << std::endl;
	else
		std::cout << "Int: " << static_cast<int>(ft_int) << std::endl;
}

void toFloat(double const &ft_float, char *argv)
{
	if (ft_check(argv) == 0)
	{
		if (ft_strcmp(argv, "-inf") == 0 || ft_strcmp(argv, "+inf") == 0 || ft_strcmp(argv, "nan") == 0 || ft_strcmp(argv, "inf") == 0)
			std::cout << "Float: " << argv << "f" << std::endl;
		else
			std::cout << "Float: " << argv << std::endl;
	}
	else if (ft_float < -std::numeric_limits<float>::infinity() || ft_float > std::numeric_limits<float>::infinity())
			std::cout << "Float: " << static_cast<float>(ft_float) << ".0f" << std::endl;  
	else if (ft_float < std::numeric_limits<float>::lowest() || ft_float > std::numeric_limits<float>::max()) 
		std::cout << "OVERFLOW" << std::endl;
	else if (g_check_point == 1)
		std::cout << "Float: " << static_cast<float>(ft_float) << "f" << std::endl;
	else
		std::cout << "Float: " << static_cast<float>(ft_float) << ".0f" << std::endl;
	
}

void toDouble(double const &ft_double, char *argv)
{
	if (ft_check(argv) == 0)
	{
		if (ft_strcmp(argv, "nanf") == 0)
			std::cout << "Double: nan" << std::endl;
		else
			std::cout << "Double: " << argv << std::endl;
	}
	else if (ft_double < -std::numeric_limits<double>::infinity() || ft_double > std::numeric_limits<double>::infinity())	
		std::cout << "OVERFLOW" << std::endl;
	else if (ft_double < std::numeric_limits<double>::lowest() || ft_double > std::numeric_limits<double>::max())
		std::cout << "OVERFLOW" << std::endl;
	else if (g_check_point == 1)
		std::cout << "Double: " << static_cast<double>(ft_double) << std::endl; 
	else
		std::cout << "Double: " << static_cast<double>(ft_double) << ".0" << std::endl; 
}
