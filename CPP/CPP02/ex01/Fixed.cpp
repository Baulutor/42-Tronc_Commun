

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value) : _value(value << _bit)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const value) : _value(roundf(value * (1 << _bit)))
{
	std::cout << "Float constructor called" << std::endl;
}

std::ostream & operator<<( std::ostream & o, Fixed const & i ) {

	o << i.toFloat();
	return o;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(src.getRawBits());
}

Fixed & Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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