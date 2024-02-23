//
// Created by dbaule on 2/23/24.
//

#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	cout << "Default WrongAnimal constructor called" << endl;
}

WrongAnimal::WrongAnimal(string type) : _type(type)
{
	cout << "Default WrongAnimal constructor called" << endl;
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
	cout << "WrongAnimal Destructor called" << endl;
}

void	WrongAnimal::makeSound() const
{
	cout << this->_type << " sound" << endl;
}

string	WrongAnimal::getType() const
{
	return (this->_type);
}
