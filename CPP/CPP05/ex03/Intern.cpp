//
// Created by dbaule on 3/28/24.
//

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"



Intern::Intern()
{
}

Intern::Intern(Intern &src)
{
    *this = src;
}

Intern & Intern::operator=(Intern &rhs)
{
    if (this != &rhs)
    {
    }
    return (*this);
}

Intern::~Intern()
{

}

AForm *Intern::makeForm(std::string name, std::string target)
{
    std::string compareString[] = {"Shrubbery", "Robotomy", "Presidential"};
    AForm *Form[] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
    for (i = 0; i < 2; i++)
    {
        if (name == compareString[i])
        {
            // il faut delete les autres
            return (Form[i])
        }
        else
            delete (Form[i]);
    }
    // throw Il n'y a pas le blaze !!

}