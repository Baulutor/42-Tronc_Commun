//
// Created by dbaule on 3/18/24.
//

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main ()
{
//    AForm abstractclass;
	try
	{
		Bureaucrat bur;

		std::cout << bur << std::endl;

		bur.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
    AForm *form[] = {new ShrubberyCreationForm(), new RobotomyRequestForm(), new PresidentialPardonForm()};
    AForm &execForm0 = *form[0];
    AForm &execForm1 = *form[1];
    AForm &execForm2 = *form[2];
	try
	{
		Bureaucrat ceo("CEO", 1);

        ceo.signForm(execForm0);
        ceo.signForm(execForm1);
        ceo.signForm(execForm2);
        ceo.executeForm(execForm0);
        ceo.executeForm(execForm1);
        ceo.executeForm(execForm2);
		std::cout << BLUE << ceo << RESET <<std::endl;
        delete (form[0]);
        delete (form[1]);
        delete (form[2]);
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
        delete (form[0]);
        delete (form[1]);
        delete (form[2]);
	}
	try
	{
		Bureaucrat executive("Pat", 25);
        RobotomyRequestForm exe("Robot");

        executive.signForm(exe);
        executive.executeForm(exe);
		std::cout << GREEN << executive << RESET <<std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

