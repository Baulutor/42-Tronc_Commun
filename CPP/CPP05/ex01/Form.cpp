//
// Created by dbaule on 3/20/24.
//

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("satisfaction"), _requiredToSign(50), _requiredToExecute(150)
{
	std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(std::string name, int gradeSign, int gradeExec) : _name(name), _requiredToSign(gradeSign), _requiredToExecute(gradeExec)
{
	std::cout << "Form constructor called" << std::endl;
	if (gradeSign > 150)
		throw GradeTooLowException();
	if (gradeSign < 1)
		throw GradeTooHighException();
	if (gradeExec > 150)
		throw GradeTooLowException();
	if (gradeExec < 1)
		throw GradeTooHighException();
}

Form::Form(Form &src) :  _name("satisfaction"), _requiredToSign(50), _requiredToExecute(150)
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = src;

}

Form &Form::operator=(Form &rhs)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_isSigned = 0;
	}
	return (*this);
}


Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

// GETTER

const std::string Form::getName()
{
	return (this->_name);
}

int Form::getRequiredToExecute()
{
	return (this->_requiredToExecute);
}

int Form::getRequiredToSign()
{
	return (this->_requiredToSign);
}

bool	Form::getIsSigned()
{
	return (this->_isSigned);
}

void Form::beSigned(Bureaucrat *bur)
{
	if (bur->getGrade() <= this->getRequiredToSign())
		this->_isSigned = 1;
	else
		throw GradeTooLowException();
}

std::ostream & operator<<(Form &src, std::ostream &o)
{
	if (src.getIsSigned() == 0)
		o << src.getName() << " is a Form, still not signed, he need a Bureaucrat that is at least " << src.getRequiredToSign() << " grade, and need to be" << src.getRequiredToExecute() << " to execute";
	else
		o << src.getName() << " is a Form, is signed, he need a Bureaucrat that is at least " << src.getRequiredToSign() << " grade, and need to be" << src.getRequiredToExecute() << " to execute";
	return (o);
}