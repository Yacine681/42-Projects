#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form 
{
	private:
	std::string m_name;
	bool m_signed;
	const int m_sign;
	const int m_execute;

	public:
	Form();
	Form(std::string name, const int m_sign, const int m_execute);
	Form(const Form &p);
	Form &operator=(const Form &p);
	~Form();

	std::string getName() const;
	bool getSigned() const;
	int getSign() const;
	int getExecute() const;

	void beSigned(const Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception {
		public:
		virtual const char * what() const throw()
		{
			return "Grade Too High!";
		}
	};

	class GradeTooLowException : public std::exception {
		public:
		virtual const char * what() const throw()
		{
			return "Grade Too low!";
		}
	};
};

std::ostream &operator<<(std::ostream &stream, const Form &src);

#endif
