//
// Created by dbaule on 3/20/24.
//

#include "AForm.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("satisfaction"), _requiredToSign(50), _requiredToExecute(150), _isSigned(0)
{
	std::cout << B_CYAN << "Default Form constructor called" << RESET << std::endl;
}

Form::Form(std::string name, int gradeSign, int gradeExec) : _name(name), _requiredToSign(gradeSign), _requiredToExecute(gradeExec), _isSigned(0)
{
	std::cout << B_CYAN << "Form constructor called" << RESET << std::endl;
	if (gradeSign > 150)
		throw GradeTooLowException();
	if (gradeSign < 1)
		throw GradeTooHighException();
	if (gradeExec > 150)
		throw GradeTooLowException();
	if (gradeExec < 1)
		throw GradeTooHighException();
}

Form::Form(Form &src) :  _name(src.getName()), _requiredToSign(src.getRequiredToSign()), _requiredToExecute(src.getRequiredToExecute()), _isSigned(0)
{
	std::cout << B_CYAN << "Form copy constructor called" << RESET << std::endl;
	*this = src;
}

Form &Form::operator=(Form &rhs)
{
	std::cout << B_CYAN << "Form copy assignment operator called" << RESET << std::endl;
	if (this != &rhs)
	{
		this->_isSigned = 0;
	}
	return (*this);
}


Form::~Form()
{
	std::cout << B_RED << "Form destructor called" << RESET << std::endl;
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
	if (this->_isSigned == 1)
		throw AlreadySigned();
	if (bur->getGrade() <= this->getRequiredToSign())
		this->_isSigned = 1;
	else
		throw GradeTooLowException();
}

std::ostream & operator<<(std::ostream &o, Form &src)
{
	if (src.getIsSigned() == 0)
		o << MAGENTA << src.getName() << " is a Form, still not signed, he need a Bureaucrat that is at least " << src.getRequiredToSign() << " grade, and need to be " << src.getRequiredToExecute() << " to execute" << RESET;
	else
		o << CYAN << src.getName() << " is a Form, is already signed, he need a Bureaucrat that is at least " << src.getRequiredToSign() << " grade, and need to be" << src.getRequiredToExecute() << " to execute" << RESET;
	return (o);
}