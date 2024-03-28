//
// Created by dbaule on 3/27/24.
//

#include "PresidentialPardonForm.hpp"


#include "AForm.hpp"

//Constructor Destructor

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential", 25, 5), _target("Bob")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &src) : AForm(src.getName(), 25, 5), _target(src._target)
{
    *this = src;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm &rhs)
{
    if (this != &rhs)
    {
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

//METHOD

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (this->getIsSigned() == 0)
        throw IsNotSigned();
    if (this->getRequiredToExecute() <= executor.getGrade())
        throw GradeTooLowToExecute();
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}



