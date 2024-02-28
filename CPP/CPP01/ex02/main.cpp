
#include <iostream>

int main ()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;


	std::cout << "This is the address of the string : " << &str << std::endl;
	std::cout << "This is the address of stringPTR : " << stringPTR << std::endl;
	std::cout << "This is the address of stringREF : " << &stringREF << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "string value : " << str << std::endl;
	std::cout << "stringPTR pointed value : " << *stringPTR << std::endl;
	std::cout << "stringREF pointed value : " << stringREF << std::endl;

}
