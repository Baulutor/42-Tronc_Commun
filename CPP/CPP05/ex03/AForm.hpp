//
// Created by dbaule on 3/20/24.
//

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

# include <cctype>
# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat;

class AForm{
private:
	std::string const	_name;
	int const			_requiredToSign;
	int const			_requiredToExecute;
	bool				_isSigned;

public :
	AForm();
	AForm(std::string name, int gradeSign, int gradeExec);
	AForm(AForm &src);
	AForm &operator=(AForm &rhs);
	virtual ~AForm();

	// GETTER AND SETTER
	std::string const	getName() const;
	int					getRequiredToSign() const;
	int			        getRequiredToExecute() const ;
	bool				getIsSigned() const;

	//METHOD

	void	beSigned(Bureaucrat *bur);

    virtual void execute(Bureaucrat const & executor) const = 0;


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
	class GradeTooLowToSign : public std::exception
	{
	public :
		virtual const char* what() const throw()
		{
			return ("Cannot sign this Form, grade of the bureaucrat too low");
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

std::ostream & operator<<(std::ostream &o, AForm &src);

#endif
