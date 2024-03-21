//
// Created by dbaule on 3/18/24.
//

#include "Bureaucrat.hpp"
#include "Form.hpp"


Bureaucrat::Bureaucrat() : _name("bur"), _grade(150)
{
	std::cout << "Default constructor Bureaucrat called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	std::cout << "Default constructor Bureaucrat called" << std::endl;
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat &src) : _name("Pierre")
{
	std::cout << "Copy constructor Bureaucrat called" << std::endl;
	*this = src;
}


Bureaucrat &Bureaucrat::operator=(Bureaucrat &rhs)
{
	std::cout << "Copy assignment operator Bureaucrat called" << std::endl;
	if (this != &rhs)
	{
		this->_grade = rhs.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor Bureaucrat called" << std::endl;
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


void Bureaucrat::signForm(Form &toSign) // lol : comment gerer si ca a ete catch et inversement ??
{
	toSign.beSigned(this);

}

// OVERLOAD

std::ostream & operator<<(std::ostream &o, Bureaucrat &bur)
{
	o << bur.getName() << ", bureaucrat grade " << bur.getGrade();
	return (o);
}
