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
	Fixed & operator=(Fixed const & rhs);
	~Fixed();
	// GETTER SETTER
	int		getRawBits() const;
	void 	setRawBits(int const raw);
	// METHOD
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream &			operator<<( std::ostream & o, Fixed const & i );

#endif