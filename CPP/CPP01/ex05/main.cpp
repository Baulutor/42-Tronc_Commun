
#include "Harl.hpp"

int main ()
{
	std::string buf;

	do
	{
		std::getline(std::cin, buf);
		Harl comp;
		comp.complain(buf);
	} while (!std::cin.eof() && buf.compare("EXIT"));
	if (std::cin.eof())
		return (0);
}
