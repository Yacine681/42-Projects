#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat 
{
	private:
	const std::string m_name;
	int m_grade;

	public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &p);
	Bureaucrat &operator=(const Bureaucrat &p);
	~Bureaucrat();

	void decremente();
	void incremente();

	std::string getName() const;
	int getGrade() const;

	class GradeTooHighException : public std::exception {
		public:
		const char * what() const throw()
		{
			return "Too High!";
		}
	};

	class GradeTooLowException : public std::exception {
		public:
		const char * what() const throw()
		{
			return "Too low!";
		}
	};
};

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &src);

#endif
