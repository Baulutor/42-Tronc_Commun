//
// Created by dbaule on 2/21/24.
//

#include "Cat.hpp"


Cat::Cat() : Animal("Cat")
{
	cout << "Default Cat constructor called" << endl;
}

Cat::Cat(Cat & rhs)
{
	this->_type = rhs._type;
}

Cat & Cat::operator=(Cat &rhs)
{
	if (&rhs != this)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

Cat::~Cat()
{
	cout << "Cat destructor" << endl;
}

void Cat::makeSound() const
{
	cout << "Meowww" << endl;
}
