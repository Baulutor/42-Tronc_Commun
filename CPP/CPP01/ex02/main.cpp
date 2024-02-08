
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::cin;

int main ()
{
	string 	str = "HI THIS IS BRAIN";
	string	*stringPTR = &str;
	string	&stringREF = str;


	cout << "This is the address of the string : " << &str << endl;
	cout << "This is the address of stringPTR : " << stringPTR << endl;
	cout << "This is the address of stringREF : " << &stringREF << endl;
	cout << "----------------------------------" << endl;
	cout << "string value : " << str << endl;
	cout << "stringPTR pointed value : " << *stringPTR << endl;
	cout << "stringREF pointed value : " << stringREF << endl;

}
