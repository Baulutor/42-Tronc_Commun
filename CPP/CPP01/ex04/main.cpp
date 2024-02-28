
#include "NewSed.hpp"

int main (int argc, char **av)
{
	if (argc != 4)
		return (std::cout << "Please put as follow : ./<executable> <filename> <finded string> <replace string>" << std::endl, 1);

	NewSed change(av[1]);
	if (change.replace(av[2], av[3]) == 1)
		return (1);
	return (0);
}
