//
// Created by dbaule on 3/18/24.
//

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main ()
{
//    AForm abstractclass;
    Intern randIntern;
    AForm   *forms;
	try
	{
		Bureaucrat executive("Pat", 20);

        forms  = randIntern.makeForm("Robotomy", "trql");
        AForm   &execForm = *forms;
        executive.signForm(execForm);
        executive.executeForm(execForm);
        delete (forms);
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

}

