//
// Created by dbaule on 2/21/24.
//

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


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

void	Animal::getCat()
{
	this = new Cat();
}

void	Animal::getDog()
{
	this = new Dog();
}
