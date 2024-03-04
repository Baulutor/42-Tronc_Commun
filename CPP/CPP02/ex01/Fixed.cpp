

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(int const value) : _value(value << _bit)
{
	std::cout << GREEN  << "Int constructor called" << RESET << std::endl;
}

Fixed::Fixed(float const value) : _value(roundf(value * (1 << _bit)))
{
	std::cout << GREEN << "Float constructor called" << RESET << std::endl;
}

std::ostream & operator<<(std::ostream &o, Fixed const &i) {

	o << i.toFloat();
	return o;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << GREEN << "Copy constructor called" << RESET << std::endl;
	this->setRawBits(src.getRawBits());
}

Fixed & Fixed::operator=(Fixed const &rhs)
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

float Fixed::toFloat( void ) const
{
	return (float)(this->getRawBits()) / (1 << this->_bit);
}

int Fixed::toInt( void ) const
{
	return (this->_value >> this->_bit);
}

int Fixed::getRawBits() const
{
	return (this->_value);
}

void Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}