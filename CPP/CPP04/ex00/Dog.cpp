
#include "Dog.hpp"


Dog::Dog() : Animal("Dog")
{
	std::cout << "Default Dog constructor Called" << std::endl;
}

Dog &Dog::operator=(Dog &rhs)
{
	std::cout << "Copy assignment operator Dog called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

Dog::Dog(Dog &src) : Animal("Dog")
{
	std::cout << "Copy constructor Dog called" << std::endl;
	this->_type = src._type;
}


Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}


void Dog::makeSound() const
{
	std::cout << "Wouuf" << std::endl;
}
