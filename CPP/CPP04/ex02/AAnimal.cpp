//
// Created by dbaule on 2/21/24.
//

#include "AAnimal.hpp"
#include "Cat.hpp"

AAnimal::AAnimal() : _type("Animal")
{
	std::cout << BLUE << "Default AAnimal constructor called" << RESET << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << BLUE << "AAnimal constructor called" << RESET << std::endl;
}

AAnimal::AAnimal(AAnimal &src)
{
	std::cout << BLUE << "Copy AAnimal constructor called" << RESET << std::endl;
	this->_type = src._type;
}

AAnimal & AAnimal::operator=(AAnimal const &rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}


AAnimal::~AAnimal()
{
	std::cout << RED << "AAnimal Destructor called" << RESET << std::endl;
}

std::string	AAnimal::getType() const
{
	return (this->_type);
}

std::string AAnimal::getIdea() const
{
	return ("Please use this as a virtual function for Cat !");
}

void AAnimal::setIdea(std::string newIdea)
{
	(void)newIdea;
	std::cout << "Please use this as a virtual function for Cat !" << std::endl;

}
