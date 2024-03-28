//
// Created by dbaule on 3/27/24.
//

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private :
    std::string _target;
public :
    // CONSTRUCTOR AND DESTRUCTOR
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(PresidentialPardonForm &src);
    PresidentialPardonForm & operator=(PresidentialPardonForm &rhs);
    ~PresidentialPardonForm();

    // METHOD
    void execute(Bureaucrat const & executor) const;

    class GradeTooLowToExecute : public std::exception
    {
    public :
        virtual const char* what() const throw()
        {
            return ("This bureaucrat can't execute the Presidential Pardon Form");
        }
    };
    class IsNotSigned : public std::exception
    {
    public :
        virtual const char* what() const throw()
        {
            return ("Cannot be executed : Presidential Pardon Form is not signed");
        }
    };
};


#endif
