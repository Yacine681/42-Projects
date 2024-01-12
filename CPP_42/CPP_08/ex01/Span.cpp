#include "Span.hpp"

Span::Span()
{
	// std::cout << "Default constructor called!" << std::endl;
	m_N = 0;
}

Span::Span(unsigned int N)
{
	// std::cout << "Unsigned int Span constructor called!" << std::endl;
	m_N = N;
}

Span::Span(const Span &p)
{
	// std::cout << "Copy constructor called!" << std::endl;
	m_N = p.m_N;
}

Span &Span::operator=(const Span &p)
{
	// std::cout << "Copy assignement operator called!" << std::endl;
	m_N = p.m_N;
	m_tab = p.m_tab;
	return (*this);
}

Span::~Span()
{
	// std::cout << "Span destructor called!" << std::endl;
}

void Span::addNumber(int N)
{
	if (m_tab.size() < m_N)
		m_tab.push_back(N);
	else
		throw Span::tabFull();
}

int Span::shortestSpan()
{
	int ft_min = 2147483647;

	std::vector<int>::iterator it1;		
	std::vector<int>::iterator it2;		
	
	for(it1 = m_tab.begin();it1!=m_tab.end();it1++)
	{
		it2 = m_tab.begin();
		for(it2 = m_tab.begin();it2!= m_tab.end(); it2++)
		{
			if (*it1 != *it2)
			{
				if (ft_min > *it1 - *it2)
				{
					if (*it2 - *it1 < 0)
						ft_min = *it1 - *it2;
					else
						ft_min = *it2 - *it1;
				}
			}
		}
	}
	return (ft_min);
}

int Span::longestSpan()
{
	unsigned int ft_min = 0;
	unsigned int ft_max = 0;

	ft_min = *std::min_element(m_tab.begin(), m_tab.end());
	ft_max = *std::max_element(m_tab.begin(), m_tab.end());

	return (ft_max - ft_min);
}

void Span::addRange(int tab_size)
{
	int nb = 0;

	srand(time(NULL));
    if (m_N  < tab_size)
	{
		std::cout << "Error limits!" << std::endl;
		exit(0);
	}
	else
    {
		std::cout << "==========" << std::endl;
        for (int i = 0; i < tab_size; i++)
		{
			nb = rand() % 50;
			std::cout << nb << std::endl;
			addNumber(nb);
		}
		std::cout << "==========" << std::endl;
	}
}
