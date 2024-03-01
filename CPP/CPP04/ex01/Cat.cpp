//
// Created by dbaule on 2/21/24.
//

#include "Cat.hpp"


Cat::Cat() : Animal("Cat")
{
	std::cout << GREEN << "Default Cat constructor called" << RESET << std::endl;
	this->_catBrain = new Brain();
}

Cat::Cat(std::string name) : Animal(name)
{
	std::cout << GREEN << "Cat constructor called" << RESET << std::endl;
	this->_catBrain = new Brain();
}

Cat::Cat(Cat & rhs)
{
	std::cout << GREEN << "Copy Cat constructor called" << RESET << std::endl;
	this->_type = rhs._type;
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
