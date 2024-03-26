//
// Created by dbaule on 3/18/24.
//

#include "Bureaucrat.hpp"
#include "AForm.hpp"


Bureaucrat::Bureaucrat() : _name("bur"), _grade(150)
{
	std::cout << B_YELLOW << "Default constructor Bureaucrat called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	std::cout << B_YELLOW << "Default constructor Bureaucrat called" << RESET << std::endl;
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat &src) : _name(src.getName())
{
	std::cout << B_YELLOW << "Copy constructor Bureaucrat called" << RESET << std::endl;
	*this = src;
}


Bureaucrat &Bureaucrat::operator=(Bureaucrat &rhs)
{
	std::cout << B_YELLOW << "Copy assignment operator Bureaucrat called" << RESET << std::endl;
	if (this != &rhs)
	{
		this->_grade = rhs.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << B_RED << "Destructor Bureaucrat called" << RESET << std::endl;
}


// GETTER

std::string const	Bureaucrat::getName()
{
	return (this->_name);
}

int			Bureaucrat::getGrade()
{
	return (this->_grade);
}

// INCREMENT/DECREMENT GRADE

void	Bureaucrat::incrementGrade()
{
	if (this->_grade > 1)
		this->_grade -= 1;
	else
		throw GradeTooHighException();
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade < 150)
		this->_grade += 1;
	else
		throw GradeTooLowException();
}

// METHOD


void Bureaucrat::signForm(Form &toSign)
{

    toSign.beSigned(this);
    std::cout << GREEN << this->_name << " signed " << toSign.getName() << RESET << std::endl;
}

// OVERLOAD

std::ostream & operator<<(std::ostream &o, Bureaucrat &bur)
{
	o << bur.getName() << ", bureaucrat grade " << bur.getGrade();
	return (o);
}
