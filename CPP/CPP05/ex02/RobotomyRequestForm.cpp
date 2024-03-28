//
// Created by dbaule on 3/27/24.
//

#include "RobotomyRequestForm.hpp"

#include "AForm.hpp"

//Constructor Destructor

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45), _target("person")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &src) : AForm(src.getName(), 72, 45), _target(src._target)
{
    *this = src;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm &rhs)
{
    if (this != &rhs)
    {
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

//METHOD

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (this->getIsSigned() == 0)
        throw IsNotSigned();
    if (this->getRequiredToExecute() <= executor.getGrade())
        throw GradeTooLowToExecute();
    std::cout << "Bzzzz Bzzzz" << std::endl;

    /* we have to change the pool of the random function,
     * cause he changed only between different compilation
     * so we change it to "point" on the time, so he will
     * generate everytime the time changed*/

    std::srand(std::time(0));
    int randomNumber = std::rand();

    if (randomNumber % 2 == 0)
        std::cout << this->_target << " has been succesfully robotomized" << std::endl;
    else
        std::cout << this->_target << " has failed to be robotomized" << std::endl;
}


