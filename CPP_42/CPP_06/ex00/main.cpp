#include "Convert.hpp"

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int ft_check(char *argv)
{
	if (ft_strcmp(argv, "-inff") == 0 || ft_strcmp(argv, "+inff") == 0 || ft_strcmp(argv, "nanf") == 0 
		|| ft_strcmp(argv, "-inf") == 0 || ft_strcmp(argv, "+inf") == 0 || ft_strcmp(argv, "nan") == 0
			|| ft_strcmp(argv, "inf") == 0 || ft_strcmp(argv, "inff") == 0)
		return (0);
	return (1);	
}

int main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Error Argument" << std::endl;
	else
		ft_parse(argv[1]);
	return (0);
}
