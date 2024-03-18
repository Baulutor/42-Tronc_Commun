//
// Created by dbaule on 2/23/24.
//

#include "WrongCat.hpp"


WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "Default WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat & rhs) : WrongAnimal("WrongCat")
{
	std::cout << "Copy constructor WrongCat called" << std::endl;
	this->_type = rhs._type;
}

WrongCat & WrongCat::operator=(WrongCat &rhs)
{
	std::cout << "Copy assignment operator WrongCat called" << std::endl;
	if (&rhs != this)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Meowww" << std::endl;
}
