//
// Created by dbaule on 2/21/24.
//

#include "Cat.hpp"


Cat::Cat() : Animal("Cat")
{
	std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat(Cat & rhs) : Animal("Cat")
{
	std::cout << "Copy constructor Cat called" << std::endl;
	this->_type = rhs._type;
}

Cat & Cat::operator=(Cat &rhs)
{
	std::cout << "Copy assignment operator Cat called" << std::endl;
	if (&rhs != this)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meowww" << std::endl;
}
