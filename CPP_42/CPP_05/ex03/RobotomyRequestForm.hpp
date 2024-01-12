#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private:
	const std::string m_target;
	RobotomyRequestForm();	

	public:
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &p);
	~RobotomyRequestForm();

	RobotomyRequestForm &operator=(const RobotomyRequestForm &p);

	void execute(const Bureaucrat &executor) const;

};

#endif
