

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(int value) : _value(value)
{
	std::cout << GREEN << "Constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << GREEN << "Copy constructor called" << RESET << std::endl;
	this->setRawBits(src.getRawBits());
}

Fixed & Fixed::operator=(Fixed &rhs)
{
	std::cout << GREEN << "Copy assignment operator called" << RESET << std::endl;
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}