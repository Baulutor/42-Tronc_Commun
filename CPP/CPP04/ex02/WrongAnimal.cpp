//
// Created by dbaule on 2/23/24.
//

#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(string type) : _type(type)
{
	std::cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &src)
{
	this->_type = src._type;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal & rhs)
{
	if (&rhs != this)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << this->_type << " sound" << std::endl;
}

string	WrongAnimal::getType() const
{
	return (this->_type);
}
