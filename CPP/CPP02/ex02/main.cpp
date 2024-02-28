
#include "Fixed.hpp"

int main( void ) {
	Fixed a(15);
	Fixed c(15);
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "value of a : " << a << std::endl;
	std::cout << "value of c : " << c << std::endl;
	std::cout << "value of b : " << b << std::endl;

	if (a == c)
		std::cout << "a == c" << std::endl;
	if (a != b)
		std::cout << "a != b" << std::endl;
	if (a > b)
		std::cout << "a is higher than b" << std::endl;
	if (a < b)
		std::cout << "b is higher than a" << std::endl;
	if (a <= c)
		std::cout << "c is higher or equal to a" << std::endl;
	if (a >= c)
		std::cout << "a is higher or equal to c" << std::endl;

	std::cout << "value of a : " << a << std::endl;
	std::cout << ++a << std::endl;

	std::cout << a++ << std::endl;
	std::cout << "value of 'a' after double incrementation : " << a << std::endl;
	std::cout << a << std::endl;
	std::cout << "------ADDITION------" << std::endl;
	std::cout << a + b << std::endl;
	std::cout << "------SUBTRACTION------" << std::endl;
	std::cout << a - b << std::endl;
	std::cout << "------DIVISION------" << std::endl;
	std::cout << a / b << std::endl;
	std::cout << "------MULTIPLICATION------" << std::endl;
	std::cout << a * b << std::endl;
	std::cout << "------COMPARISON------" << std::endl;

	std::cout << "value of a : " << a << std::endl;
	std::cout << a << std::endl;
	std::cout << "pre-decrement : ";
	std::cout << --a << std::endl;
	std::cout << "post-decrement : ";
	std::cout << a-- << std::endl;
	std::cout << std::endl;
	std::cout << "value of a : " << a << std::endl;
	std::cout << "value of b : " << b << std::endl;

	std::cout << "the biggest value between those two : ";
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "the smallest value between those two : ";
	std::cout << Fixed::min(a, b) << std::endl;
	return 0;
}