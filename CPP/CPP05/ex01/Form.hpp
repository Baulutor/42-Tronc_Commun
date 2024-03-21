//
// Created by dbaule on 3/20/24.
//

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

# include <cctype>
# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat;

class Form{
private:
	std::string const	_name;
	int const			_requiredToSign;
	int const			_requiredToExecute;
	bool				_isSigned;

public :
	Form();
	Form(std::string name, int gradeSign, int gradeExec);
	Form(Form &src);
	Form &operator=(Form &rhs);
	~Form();

	// GETTER AND SETTER
	std::string const	getName();
	int					getRequiredToSign();
	int					getRequiredToExecute();
	bool				getIsSigned();


	//METHOD

	void	beSigned(Bureaucrat *bur);
	// EXCEPTION
	class	GradeTooHighException : public std::exception
	{
	public :
		virtual const char* what() const throw()
		{
			return ("Grade is too high, 1 is the maximum");
		}
	};
	class	GradeTooLowException : public std::exception
	{
	public :
		virtual const char* what() const throw()
		{
			return ("Grade is too low, 150 is the minimum");
		}
	};
	class AlreadySigned : public std::exception
	{
	public :
		virtual const char* what() const throw()
		{
			return ("The form is already signed");
		}
	};
};

std::ostream & operator<<(std::ostream &o, Form &src);

#endif
