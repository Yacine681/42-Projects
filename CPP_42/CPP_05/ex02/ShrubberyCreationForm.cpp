#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : Form("ShrubberyCreationForm", 145, 137),  m_target(target)
{
	// std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &p) : Form(p), m_target(p.m_target) 
{
	// std::cout << "ShrubberyCreationForm copy constructor called" << std::enld;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &p)
{
	(void)p;
	return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const 
{
    if (this->getSigned() == false)
        throw Form::NotSignedException();
    else if (executor.getGrade() > this->getExecute())
	{
		throw Form::GradeTooLowException();
	}	
	std::ofstream file(this->getName() + "_shrubbery");
	file << "      	 .   ._, |_  .," << std::endl;
    file << "       `-._||  .  | /    |/_" << std::endl;
    file << "           \\  _|| y | ||/" << std::endl;
    file << "     _||.___\\, \\/ -.|||" << std::endl;
    file << "      ` -,--.`._||  / / ," << std::endl;
    file << "       /'     `-. `./ / |/_.'" << std::endl;
    file << "                 |    |//" << std::endl;
    file << "                 |_    /" << std::endl;
    file << "                 |-   |" << std::endl;
    file << "                 |   =|" << std::endl;
    file << "                 |    |" << std::endl;
	file.close();
}
