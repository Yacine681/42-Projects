#ifndef PRESIDENTIALPARDONFORM_HPP 
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	private:
	std::string m_target;

	PresidentialPardonForm();	

	public:
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &p);
	~PresidentialPardonForm();

	PresidentialPardonForm &operator=(const PresidentialPardonForm &p);

	void execute(const Bureaucrat &executor) const;

};

#endif