//
// Created by dbaule on 3/20/24.
//

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("satisfaction"), _requiredToSign(50), _requiredToExecute(150), _isSigned(0)
{
	std::cout << B_CYAN << "Default AForm constructor called" << RESET << std::endl;
}

AForm::AForm(std::string name, int gradeSign, int gradeExec) : _name(name), _requiredToSign(gradeSign), _requiredToExecute(gradeExec), _isSigned(0)
{
	std::cout << B_CYAN << "AForm constructor called" << RESET << std::endl;
	if (gradeSign > 150)
		throw GradeTooLowException();
	if (gradeSign < 1)
		throw GradeTooHighException();
	if (gradeExec > 150)
		throw GradeTooLowException();
	if (gradeExec < 1)
		throw GradeTooHighException();
}

AForm::AForm(AForm &src) :  _name(src.getName()), _requiredToSign(src.getRequiredToSign()), _requiredToExecute(src.getRequiredToExecute()), _isSigned(0)
{
	std::cout << B_CYAN << "AForm copy constructor called" << RESET << std::endl;
	*this = src;
}

AForm &AForm::operator=(AForm &rhs)
{
	std::cout << B_CYAN << "AForm copy assignment operator called" << RESET << std::endl;
	if (this != &rhs)
	{
		this->_isSigned = 0;
	}
	return (*this);
}


AForm::~AForm()
{
	std::cout << B_RED << "AForm destructor called" << RESET << std::endl;
}

// GETTER

const std::string AForm::getName() const
{
	return (this->_name);
}

int AForm::getRequiredToExecute() const
{
	return (this->_requiredToExecute);
}

int AForm::getRequiredToSign() const
{
	return (this->_requiredToSign);
}

bool	AForm::getIsSigned() const
{
	return (this->_isSigned);
}

void AForm::beSigned(Bureaucrat *bur)
{
	if (this->_isSigned == 1)
		throw AlreadySigned();
	if (bur->getGrade() <= this->getRequiredToSign())
		this->_isSigned = 1;
	else
        std::cout << bur->getName() << " couldn't signed " << this->getName() << " because the grade is too low" << std::endl;
}

std::ostream & operator<<(std::ostream &o, AForm &src)
{
	if (src.getIsSigned() == 0)
		o << MAGENTA << src.getName() << " is a form, still not signed, he need a Bureaucrat that is at least " << src.getRequiredToSign() << " grade, and need to be " << src.getRequiredToExecute() << " to execute" << RESET;
	else
		o << CYAN << src.getName() << " is a form, is already signed, he need a Bureaucrat that is at least " << src.getRequiredToSign() << " grade, and need to be" << src.getRequiredToExecute() << " to execute" << RESET;
	return (o);
}

