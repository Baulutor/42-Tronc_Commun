//
// Created by dbaule on 3/27/24.
//

#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
    private :
        std::string _target;

    public :
        // CONSTRUCTOR AND DESTRUCTOR
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm &src);
        RobotomyRequestForm & operator=(RobotomyRequestForm &rhs);
        ~RobotomyRequestForm();

        // METHOD
        void execute(Bureaucrat const & executor) const;

        class GradeTooLowToExecute : public std::exception
        {
        public :
            virtual const char* what() const throw()
            {
                return ("This bureaucrat can't execute the Robotomy Request Form");
            }
        };
        class IsNotSigned : public std::exception
        {
        public :
            virtual const char* what() const throw()
            {
                return ("Cannot be executed : Robotomy Request Form is not signed");
            }
    };
};



#endif
