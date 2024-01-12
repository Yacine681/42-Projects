#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form("PresidentialPardonForm", 25, 5),  m_target(target)
{
	// std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &p) : Form(p), m_target(p.m_target) 
{
	// std::cout << "PresidentialPardonForm copy constructor called" << std::enld;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &p)
{
	(void)p;
	return(*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	// std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const 
{
	if (this->getSigned() == false)
        throw Form::NotSignedException();
    if ( executor.getGrade() > this->getExecute() )
        throw Form::GradeTooLowException();
    else 
        std::cout << m_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
