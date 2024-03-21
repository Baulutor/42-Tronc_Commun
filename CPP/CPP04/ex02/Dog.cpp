
#include "Dog.hpp"


Dog::Dog() : AAnimal("Dog")
{
	std::cout << GREEN << "Default Dog constructor Called" << RESET << std::endl;
	this->_dogBrain = new Brain();
}

Dog::Dog(std::string name) : AAnimal(name)
{
	std::cout << GREEN << "Dog constructor called" << RESET << std::endl;
	this->_dogBrain = new Brain();
}

Dog::Dog(Dog &src) : AAnimal()
{
	std::cout << GREEN << "Copy Dog constructor called" << RESET << std::endl;
	this->_type = src._type;
	this->_dogBrain = new Brain();
}

Dog & Dog::operator=(Dog &rhs)
{
	std::cout << GREEN << "Operator assignation called" << RESET << std::endl;
	if (this != &rhs)
	{
		this->_dogBrain = new Brain();
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << RED << "Dog Destructor called" << RESET << std::endl;
	delete(this->_dogBrain);
}


void Dog::makeSound() const
{
	std::cout << "Wouuf" << std::endl;
}
