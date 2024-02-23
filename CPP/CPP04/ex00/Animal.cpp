//
// Created by dbaule on 2/21/24.
//

#include "Animal.hpp"


Animal::Animal() : _type("Animal")
{
	cout << "Default Animal constructor called" << endl;
}

Animal::Animal(string type) : _type(type)
{
	cout << "Default Animal constructor called" << endl;
}

Animal::Animal(Animal &src)
{
	this->_type = src._type;
}

Animal & Animal::operator=(Animal & rhs)
{
	if (&rhs != this)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

Animal::~Animal()
{
	cout << "Animal Destructor called" << endl;
}

void	Animal::makeSound() const
{
	cout << this->_type<< " sound" << endl;
}

string	Animal::getType() const
{
	return (this->_type);
}
