
#include "Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name)
{
	Zombie	*horde = new Zombie[n];

	for (int i = 0; i < n; i++)
	{
		horde[i].setName(name);
	}
	return (horde);
}

void	Zombie::setName(std::string str)
{
	this->_name = str;
}
