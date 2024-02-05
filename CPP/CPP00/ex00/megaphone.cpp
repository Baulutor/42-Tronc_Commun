
#include <cctype>
#include <string>
#include <iostream>

int main (int argc, char **argv)
{
	std::string str;
	int i;

	if (argc < 2)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl,  0);
	i = 1;
	while (argv[i])
	{
		str = argv[i];
		for (unsigned long i = 0; i < str.length(); ++i)
			str[i] = std::toupper(str[i]);
		std::cout << str;
		i++;
	}
	std::cout << std::endl;
}