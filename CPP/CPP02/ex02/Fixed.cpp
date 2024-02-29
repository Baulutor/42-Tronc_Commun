

#include "Fixed.hpp"

/* -------------------CONSTRUCTOR AND DESTRUCTOR WITH BASE OPERATOR------------------- */

Fixed::Fixed() : _value(0)
{
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(int const value) : _value(value << _bit)
{
	std::cout << GREEN << "Int constructor called" << RESET << std::endl;
}

Fixed::Fixed(float const value) : _value(roundf(value * (1 << _bit)))
{
	std::cout << GREEN << "Float constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << GREEN << "Copy constructor called" << RESET << std::endl;
	this->setRawBits(src.getRawBits());
}

Fixed::~Fixed()
{
	std::cout << RED << "Destructor called" << RESET <<  std::endl;
}



/* -------------------GETTER AND SETTER------------------- */

int Fixed::getRawBits() const
{
	return (this->_value);
}

void Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}

/* -------------------OPERATION------------------- */

float Fixed::toFloat( void ) const
{
	return (float)(this->getRawBits()) / (1 << this->_bit);
}

int Fixed::toInt( void ) const
{
	return (this->_value >> this->_bit);
}


/* -------------------OVERLOAD ------------------- */

std::ostream& operator<<( std::ostream & o, Fixed const & i ) {

	o << i.toFloat();
	return o;
}

Fixed & Fixed::operator=(Fixed const &rhs)
{
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return (*this);
}

/* COMPARISON */

bool	Fixed::operator>(Fixed const & rhs)
{
	return (this->_value > rhs._value);
}

bool	Fixed::operator>=(Fixed const & rhs)
{
	return (this->_value >= rhs._value);
}

bool	Fixed::operator<(Fixed const & rhs)
{
	return (this->_value < rhs._value);
}

bool	Fixed::operator<=(Fixed const & rhs)
{
	return (this->_value <= rhs._value);
}

bool	Fixed::operator!=(Fixed const & rhs)
{
	return (this->_value != rhs._value);
}

bool	Fixed::operator==(Fixed const & rhs)
{
	return (this->_value == rhs._value);
}


/* INCREMENT AND DECREMENT */


Fixed Fixed::operator++()
{
	this->_value += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed a;
	a._value = this->_value;
	this->_value += 1;
	return (a);
}

Fixed	Fixed::operator--()
{
	this->_value -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	a;
	a._value = this->_value;
	this->_value -= 1;
	return (a);
}

/* OPERATOR_ARITHMETIC */

Fixed	Fixed::operator*(const	Fixed & rhs)
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator+(const Fixed & rhs)
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator/(const Fixed & rhs)
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed	Fixed::operator-(const Fixed & rhs)
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}


/*	-------------------MIN AND MAX------------------- */

Fixed	& Fixed::min(Fixed & a, Fixed & b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b);
	return a;
}

Fixed	const & Fixed::min(Fixed const & a, Fixed const & b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b);
	return a;
}

Fixed  & Fixed::max(Fixed & a, Fixed & b)
{
	if (a.getRawBits() < b.getRawBits())
		return (b);
	return a;
}

Fixed const &	Fixed::max(Fixed const & a, Fixed const & b)
{
	if (a.getRawBits() < b.getRawBits())
		return (b);
	return a;
}