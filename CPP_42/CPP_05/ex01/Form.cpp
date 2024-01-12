#include "Form.hpp"

Form::Form() : m_name("default"), m_signed(false), m_sign(150), m_execute(150) 
{
	// std::cout << "Default constructor called" << std::endl;
}

Form::Form(std::string name, int sign, int execute) : m_name(name), m_sign(sign), m_execute(execute)
{
	// std::cout << "std::string Form constructor called!" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(const Form &p) : m_name(p.m_name), m_signed(p.m_signed), m_sign(p.m_sign), m_execute(p.m_execute)
{
	std::cout << "Copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &p)
{
	std::cout << "Form copy assignement operator called" << std::endl;
	return (*this);
}

std::string Form::getName() const 
{
	return (m_name);
}

bool Form::getSigned() const
{
	return (m_signed);
}

int Form::getSign() const
{
	return (m_sign);
}

int Form::getExecute() const
{
	return (m_execute);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() >= m_sign)
		throw Form::GradeTooLowException();
	m_signed = true;
}

std::ostream &operator<<(std::ostream &stream, const Form &obj)
{
	stream << "------------- Form Info ------------- " << std::endl;
	stream << "Form name: " << obj.getName() << std::endl;
	stream << "Grade to sign: " << obj.getSign() << std::endl;
	stream << "Grade to execute: " << obj.getExecute() << std::endl;
	return (stream);	
}	
