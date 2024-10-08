//
// Created by dbaule on 3/18/24.
//

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include <cctype>
#include <string>
#include <iostream>
#include <stdexcept>

# define RED "\033[31m"
# define RESET "\033[0m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"

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
	int			getGrade();
	std::string	const getName();
	// METHOD
	void	incrementGrade();
	void	decrementGrade();


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
};
	// OVERLOAD
	std::ostream & operator<<(std::ostream &o, Bureaucrat &bur);



#endif
