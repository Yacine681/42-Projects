#include "Rpn.hpp"

Rpn::Rpn()
{
	// std::cout << "Constructor called!" << std::endl;
}

Rpn::Rpn(const Rpn &p)
{
	// std::cout << "Copy constructor called!" << std::endl;
}

Rpn &Rpn::operator=(const Rpn &p)
{
	// std::cout << "Copy assignement operator called!" << std::endl;
	return *this;
}

Rpn::~Rpn()
{
	// std::cout << "Destructor called!" << std::endl;
}

int Rpn::Calculate(std::string rpn)
{
	int nb1;
	int nb2;

	for(int i=0;i < rpn.length();i++)
	{
		if (rpn[i] == ' ')
			continue ;
		else if (isdigit(rpn[i]))
		{
			nb1 = stoi(std::string(1, rpn[i]));
			stack_rpn.push(nb1);
		}
		else
		{
			nb2 = stack_rpn.top();
			stack_rpn.pop();

			if (stack_rpn.empty())
			{
				std::cout << "Error" << std::endl;
				exit(0);
			}

			nb1 = stack_rpn.top();
			stack_rpn.pop();
			
			if (rpn[i] == '+')
				stack_rpn.push(nb1 + nb2);
			else if (rpn[i] == '-')
				stack_rpn.push(nb1 - nb2);
			else if (rpn[i] == '/')
				stack_rpn.push(nb1 / nb2);
			else if (rpn[i] == '*')
				stack_rpn.push(nb1 * nb2);
		}
	}
	return (stack_rpn.top());
}

int Rpn::check_error(std::string argv)
{
	for(int i=0;argv[i];i++)
	{
		if (isdigit(argv[i]) == false)
		{
			if (argv[i] == '+' || argv[i] == '-' || argv[i] == '/'
					|| argv[i] == '*' || argv[i] == ' ')
				continue ;
			else
				return (-1);
		}
	}
	return (0);
}
