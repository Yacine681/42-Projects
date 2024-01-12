#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : m_name("Default") 
{
	// std::cout << "Bureaucrat constructor called!" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : m_name(name), m_grade(grade)
{
	// std::cout << "std::string Bureaucrat constructor called!" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << "Bureaucrat constructor called!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &p) : m_name(p.m_name), m_grade(p.m_grade)
{
	// std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &p)
{
	// std::cout << "Bureaucrat copy assignement operator called" << std::endl;
	m_grade = p.m_grade;
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return(m_name);
}

int Bureaucrat::getGrade() const
{
	return (m_grade);
}

void Bureaucrat::decremente()
{
	if (m_grade + 1 > 150) 
		throw Bureaucrat::GradeTooLowException();
	m_grade++;
}

void Bureaucrat::incremente()
{
	if (m_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	m_grade--;
}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &obj)
{
	stream << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (stream);	
}
