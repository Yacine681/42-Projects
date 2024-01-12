#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <iostream>

class ShrubberyCreationForm : public Form
{
	private:
	const std::string m_target;
	ShrubberyCreationForm();	

	public:
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &p);
	~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &p);

	void execute(const Bureaucrat &executor) const;

};

#endif
 
