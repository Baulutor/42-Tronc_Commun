

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(int const value) : _value(value << _bit)
{
	cout << "Int constructor called" << endl;
}

Fixed::Fixed(float const value) : _value(roundf(value * (1 << _bit)))
{
	cout << "Float constructor called" << endl;
}

std::ostream & operator<<( std::ostream & o, Fixed const & i ) {

	o << i.toFloat();
	return o;
}

Fixed::Fixed(const Fixed &src)
{
	cout << "Copy constructor called" << endl;
	this->setRawBits(src.getRawBits());
}

Fixed & Fixed::operator=(Fixed const &rhs)
{
	cout << "Copy assignment operator called" << endl;
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
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