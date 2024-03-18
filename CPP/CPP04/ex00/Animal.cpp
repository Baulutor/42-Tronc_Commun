//
// Created by dbaule on 2/21/24.
//

#include "Animal.hpp"


Animal::Animal() : _type("Animal")
{
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(Animal &src)
{
	std::cout << "Copy constructor Animal called" << std::endl;
	this->_type = src._type;
}

Animal & Animal::operator=(Animal & rhs)
{
	std::cout << "Copy assignment operator Animal called" << std::endl;
	if (&rhs != this)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << this->_type<< " sound" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->_type);
}
