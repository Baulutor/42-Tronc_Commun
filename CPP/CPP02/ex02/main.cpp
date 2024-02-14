
#include "Fixed.hpp"

int main( void ) {
	Fixed a(15);
	Fixed c(15);
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "value of a : " << a << std::endl;
	cout << "value of c : " << c << endl;
	cout << "value of b : " << b << endl;

	if (a == c)
		cout << "a == c" << endl;
	if (a != b)
		cout << "a != b" << endl;
	if (a > b)
		cout << "a is higher than b" << endl;
	if (a < b)
		cout << "b is higher than a" << endl;
	if (a <= c)
		cout << "c is higher or equal to a" << endl;
	if (a >= c)
		cout << "a is higher or equal to c" << endl;

	cout << "value of a : " << a << endl;
	std::cout << ++a << std::endl;

	std::cout << a++ << std::endl;
	cout << "value of 'a' after double incrementation : " << a << endl;
	std::cout << a << std::endl;
	cout << "------ADDITION------" << endl;
	cout << a + b << endl;
	cout << "------SUBTRACTION------" << endl;
	cout << a - b << endl;
	cout << "------DIVISION------" << endl;
	cout << a / b << endl;
	cout << "------MULTIPLICATION------" << endl;
	cout << a * b << endl;
	cout << "------COMPARISON------" << endl;

	cout << "value of a : " << a << endl;
	std::cout << a << std::endl;
	cout << "pre-decrement : ";
	std::cout << --a << std::endl;
	cout << "post-decrement : ";
	std::cout << a-- << std::endl;
	cout << endl;
	std::cout << "value of a : " << a << std::endl;
	std::cout << "value of b : " << b << std::endl;

	cout << "the biggest value between those two : ";
	std::cout << Fixed::max( a, b ) << std::endl;
	cout << "the smallest value between those two : ";
	cout << Fixed::min(a, b) << endl;
	return 0;
}