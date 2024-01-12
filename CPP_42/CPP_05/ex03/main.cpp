#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern someRandomIntern;
	Form* rrf;
	Form* test;
	Form* test1;

	
	rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
	test = someRandomIntern.makeForm("robotomy request", "Bender");
	test1 = someRandomIntern.makeForm("presidential pardon", "Bender");

	delete rrf;
	delete test;
	delete test1;
}
