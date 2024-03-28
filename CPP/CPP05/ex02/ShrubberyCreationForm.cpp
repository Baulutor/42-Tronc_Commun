//
// Created by dbaule on 3/26/24.
//

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

//Constructor Destructor

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137), _target("Home")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &src) : AForm("Shrubbery", 145, 137)
{
    *this = src;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm &rhs)
{
    if (this != &rhs)
    {
        this->_target = rhs._target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

//METHOD

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (this->getIsSigned() == 0)
        throw IsNotSigned();
    if (this->getRequiredToExecute() <= executor.getGrade())
        throw GradeTooLowToExecute();
    std::string buf;

    buf = this->_target + "_shrubbery";

    std::ofstream file(buf.c_str(), std::ios::app);

    if (file.is_open())
    {
        file << "       _-_" << std::endl <<
                   "    /~~   ~~\\" << std::endl <<
                   " /~~         ~~\\" << std::endl <<
                   "{               }" << std::endl <<
                   " \\  _-     -_  /" << std::endl <<
                   "   ~  \\\\ //  ~" << std::endl <<
                   "_- -   | | _- _" << std::endl <<
                   "  _ -  | |   -_" << std::endl <<
                   "      // \\\\" << std::endl;
    }
    else
        throw CantOpen();
}



