#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{

    try {
        Bureaucrat bureaucrat("ash", 2);
		ShrubberyCreationForm form1("Shrubbery");

        RobotomyRequestForm form2("Robotomy");
        PresidentialPardonForm form3("President");

        std::cout << "\n--------------- Form 1 (Shrubbery) ---------------" << std::endl;
        bureaucrat.signForm(form1);
        bureaucrat.executeForm(form1);

        std::cout << "\n--------------- Form 2 (Robotomy) ---------------" << std::endl;
        bureaucrat.signForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);

        std::cout << "\n--------------- Form 3 (President) ---------------" << std::endl;
        bureaucrat.signForm(form3);
        bureaucrat.executeForm(form3);

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
