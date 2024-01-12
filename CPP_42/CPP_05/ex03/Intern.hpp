#ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:

	public:
	Intern();
	Intern(const Intern &p);
	Intern &operator=(const Intern &p);
	~Intern();	
	
	Form *makeForm(std::string name, std::string target);
};

#endif
