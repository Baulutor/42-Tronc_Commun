//
// Created by dbaule on 3/26/24.
//

#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H


#include "AForm.hpp"
#include <fstream>
#include <cstring>

//class AForm;

class ShrubberyCreationForm : public AForm
{
private :
    std::string _target;

public :
    // CONSTRUCTOR AND DESTRUCTOR
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm &src);
    ShrubberyCreationForm & operator=(ShrubberyCreationForm &rhs);
    ~ShrubberyCreationForm();

    // METHOD
    void execute(Bureaucrat const & executor) const;

    class GradeTooLowToExecute : public std::exception
    {
    public :
        virtual const char* what() const throw()
        {
            return ("This bureaucrat can't execute Shrubbery form");
        }
    };
    class IsNotSigned : public std::exception
    {
    public :
        virtual const char* what() const throw()
        {
            return ("Cannot be executed : Shrubbery form is not signed");
        }
    };
    class CantOpen : public std::exception
    {
    public :
        virtual const char* what() const throw()
        {
            return ("Cannot go to the target to put a three");
        }
    };
};


#endif
