#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array 
{
	private:

	T *m_tab;
	unsigned int m_n;	

	public:

	Array()
	{
		// std::cout << "Constructor called!" << std::endl;
		m_tab = new T();
		m_n = 0;
	}
	
	Array(unsigned int n)
	{
		// std::cout << "unsigned int n constructor called!" << std::endl;		
		m_tab = new T[n];
		m_n = n;
	}
	
	Array(const Array<T> &p)
	{
		// std::cout << "Copy constructor called!" << std::endl;
		m_tab = new T[p.m_n];
		m_n = p.m_n;
		for(int i = 0;i < m_n;i++)
		  m_tab[i] = p.m_tab[i];
	}
	
	Array &operator=(const Array<T> &p)
	{
		m_tab = new T[p.m_n];
		m_n = p.m_n;
		for(int i = 0;i < m_n;i++)
		  m_tab[i] = p.m_tab[i];
		return *this;
	}
		
	T &operator[](unsigned int i) {
		if (i >= m_n)
			throw invalidIndex();
		return m_tab[i];
	}
	
	~Array()
	{
		// std::cout << "Destructor called" << std::endl;
		delete[] m_tab;
	}
	
	class invalidIndex : public std::exception {
		public:
		const char * what() const throw()
		{
			return "Invalid Index!";
		}
	};

	T size()
	{
		return (m_n);
	}

	void print()
	{
		for(int i = 0;m_tab[i];i++)
			std::cout << m_tab[i] << std::endl;
	}
};

#endif
