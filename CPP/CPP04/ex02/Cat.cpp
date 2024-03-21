//
// Created by dbaule on 2/21/24.
//

#include "Cat.hpp"


Cat::Cat() : AAnimal("Cat")
{
	std::cout << GREEN << "Default Cat constructor called" << RESET << std::endl;
	this->_catBrain = new Brain();
}

Cat::Cat(std::string name) : AAnimal(name)
{
	std::cout << GREEN << "Cat constructor called" << RESET << std::endl;
	this->_catBrain = new Brain();
}

Cat & Cat::operator=(Cat &rhs)
{
	std::cout << GREEN << "Operator assignation called" << RESET << std::endl;
	if (this != &rhs)
	{
		this->_catBrain = new Brain();
	}
	return (*this);
}

Cat::Cat(Cat & rhs) : AAnimal()
{
	std::cout << GREEN << "Copy Cat constructor called" << RESET << std::endl;
	this->_type = rhs._type;
	this->_catBrain = new Brain();
}

Cat::~Cat()
{
	std::cout << RED << "Cat destructor called" << RESET << std::endl;
	delete(this->_catBrain);
}

void Cat::makeSound() const
{
	std::cout << "Meowww" << std::endl;
}

std::string Cat::getIdea() const
{
	std::string test;

	test = this->_catBrain->getFirstIdea();
	return (test);
}

void	Cat::setIdea(std::string newIdea)
{
	this->_catBrain->setFirstIdea(newIdea);
}