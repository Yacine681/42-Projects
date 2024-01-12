#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	private:

	public:
	MutantStack() {}
	
	MutantStack(const MutantStack &p)
	{
		*this = *p;	
	}
	MutantStack &operator=(const MutantStack &p)
	{
		std::stack<T>::c = p.c;
		return *this;
	}
	
	~MutantStack() {}
	
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin()
	{
		return (std::stack<T>::c.begin());
	}
	iterator end()
	{
		return (std::stack<T>::c.end());
	}
};

#endif
