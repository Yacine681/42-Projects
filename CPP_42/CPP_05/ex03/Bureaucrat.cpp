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

void Bureaucrat::signForm(Form& form)
{
	try {
		form.beSigned(*this);
		std::cout << *this <<" signed " << form.getName() << std::endl;
	} catch (Form::GradeTooLowException &e) {
		std::cout << m_name << " couldn't sign " << form.getName() << " beacause " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const Form& form) const 
{
    try 
	{
        form.execute(*this);
    } 
	catch (std::exception& e)
	{
        std::cout << m_name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &obj)
{
	stream << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (stream);	
}
