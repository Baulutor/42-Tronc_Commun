#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <fstream>
# include <ostream>
# include <cmath>

class Fixed
{
private :
	int 				_value;
	static const int	_bit = 8;
public :
	//CONSTRUCTOR AND DESTRUCTOR
	Fixed();
	Fixed(int const value);
	Fixed(float const value);
	Fixed(Fixed const & src);
	~Fixed();
	// GETTER SETTER
	int		getRawBits() const;
	void 	setRawBits(int const raw);
	// OPERATOR
	Fixed	operator++();
	Fixed	operator++(int);
	Fixed	operator--();
	Fixed	operator--(int);


	Fixed	operator*(const Fixed & rhs);
	Fixed	operator+(const Fixed & rhs);
	Fixed	operator-(const Fixed & rhs);
	Fixed	operator/(const Fixed & rhs);

	bool	operator>(Fixed const & rhs);
	bool	operator>=(Fixed const & rhs);
	bool	operator<(Fixed const & rhs);
	bool	operator<=(Fixed const & rhs);
	bool	operator==(Fixed const & rhs);
	bool	operator!=(Fixed const & rhs);

	Fixed & operator=(Fixed const & rhs);
	// METHOD


	float	toFloat( void ) const;
	int		toInt( void ) const;
	static	Fixed	& min(Fixed & a, Fixed & b);
	static	Fixed	const & min(Fixed const & a, Fixed const & b);
	static	Fixed	& max(Fixed & a, Fixed & b);
	static	Fixed	const & max(Fixed const & a, Fixed const & b);

};

std::ostream &	operator<<( std::ostream & o, Fixed const & i );

#endif