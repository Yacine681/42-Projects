#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
	private:
	unsigned int m_N;
	std::vector<int> m_tab;	

	public:
	Span();
	Span(unsigned int N);
	Span(const Span &p);
	Span &operator=(const Span &p);
	~Span();
	
	void addRange(int tab_size);
	void addNumber(int n);
	int shortestSpan();
	int longestSpan();

	class tabFull : public std::exception {
		public:
		const char * what() const throw()
		{
			return "Tab Full!";
		}
	};
};

#endif
