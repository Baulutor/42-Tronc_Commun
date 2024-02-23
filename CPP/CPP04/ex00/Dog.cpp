
#include "Dog.hpp"


Dog::Dog() : Animal("Dog")
{
	cout << "Default Dog constructor Called" << endl;
}

Dog &Dog::operator=(Dog &rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

Dog::Dog(Dog &src)
{
	this->_type = src._type;
}


Dog::~Dog()
{
	cout << "Dog Destructor called" << endl;
}


void Dog::makeSound() const
{
	cout << "Wouuf" << endl;
}
