//
// Created by dbaule on 2/23/24.
//

#include "WrongCat.hpp"


WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	cout << "Default WrongCat constructor called" << endl;
}

WrongCat::WrongCat(WrongCat & rhs)
{
	this->_type = rhs._type;
}

WrongCat & WrongCat::operator=(WrongCat &rhs)
{
	if (&rhs != this)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	cout << "WrongCat destructor" << endl;
}

void WrongCat::makeSound() const
{
	cout << "Meowww" << endl;
}
