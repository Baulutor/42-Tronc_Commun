//
// Created by dbaule on 3/18/24.
//

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "AForm.hpp"

# include <cctype>
# include <string>
# include <iostream>
# include <stdexcept>

# define RED		"\033[31m"
# define RESET		"\033[0m"
# define GREEN		"\033[32m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define YELLOW		"\033[33m"
# define B_YELLOW	"\033[43m"
# define B_RED      "\033[41m"
# define B_CYAN     "\033[46m"

class Form;

class Bureaucrat {
private:
	std::string	const	_name;
	int 				_grade;
public:
	// CONSTRUCTOR AND DESTRUCTOR
	Bureaucrat();
	Bureaucrat(std::string const name, int grade);
	Bureaucrat(Bureaucrat &src);
	Bureaucrat &operator=(Bureaucrat &rhs);
	~Bureaucrat();

	// GETTER SETTER
	int					getGrade();
	std::string	const	getName();
	// METHOD
	void	incrementGrade();
	void	decrementGrade();

	void	signForm(Form &toSign);

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
	// OVERLOAD
	std::ostream & operator<<(std::ostream &o, Bureaucrat &bur);



#endif
