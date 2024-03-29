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
    for (int i = 0; i < 3; i++)
    {
        if (name == compareString[i])
        {
            for (int j =  i + 1; j < 3; j++)
                delete(Form[j]);
            return (Form[i]);
        }
        else
            delete (Form[i]);
    }
    throw NoNameForm();

}