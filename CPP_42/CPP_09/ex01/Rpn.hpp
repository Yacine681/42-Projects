#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>

class Rpn {

	private:
	std::stack<int>stack_rpn;

	public:
	Rpn();
	Rpn(const Rpn &p);
	Rpn &operator=(const Rpn &p);
	~Rpn();
	
	int Calculate(std::string rpn);
	int check_error(std::string argv);
};

#endif
