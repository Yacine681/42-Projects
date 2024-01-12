#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form("RobotomyRequestForm", 72, 45),  m_target(target)
{
	// std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &p) : Form(p), m_target(p.m_target) 
{
	// std::cout << "RobotomyRequestForm copy constructor called" << std::enld;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &p)
{
	(void)p;
	return(*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const 
{	
	if (this->getSigned() == false)
        throw Form::NotSignedException();
    if ( executor.getGrade() > this->getExecute() )
        throw Form::GradeTooLowException();
    else {
		static int i = 0;
		if (i % 2 == 0)
			std::cout << "BZZZZ " << m_target << "has been robotomized" << std::endl;
		else
        	std::cout << "Operation Failed !" << std::endl;
		i++;
    }
}
