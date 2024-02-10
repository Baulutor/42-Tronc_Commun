#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

class Fixed
{
private :
	int 				_value;
	static const int	_bit = 8;
public :
	//CONSTRUCTOR AND DESTRUCTOR
	Fixed();
	Fixed(Fixed const & src);
	Fixed & operator=(Fixed & rhs);
	~Fixed();
	// GETTER SETTER
	int		getRawBits() const;
	void 	setRawBits(int const raw);
};

#endif