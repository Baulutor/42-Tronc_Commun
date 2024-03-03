//
// Created by dbaule on 2/21/24.
//

#include "Animal.hpp"
#include "Cat.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << BLUE << "Default Animal constructor called" << RESET << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << BLUE << "Animal constructor called" << RESET << std::endl;
}

Animal::Animal(Animal &src)
{
	std::cout << BLUE << "Copy Animal constructor called" << RESET << std::endl;
	this->_type = src._type;
}

Animal & Animal::operator=(Animal const &rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}


Animal::~Animal()
{
	std::cout << RED << "Animal Destructor called" << RESET << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << this->_type<< " sound" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->_type);
}

std::string Animal::getIdea() const
{
	return ("Please use this as a virtual function for Cat !");
}

void Animal::setIdea(std::string newIdea)
{
	(void)newIdea;
	std::cout << "Please use this as a virtual function for Cat !" << std::endl;

}
