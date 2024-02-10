
#include "Harl.hpp"

int main ()
{
	string buf;

	do
	{
		getline(cin, buf);
		Harl comp;
		comp.complain(buf);
	} while (!cin.eof() && buf.compare("EXIT"));
	if (cin.eof())
		return (0);
}
