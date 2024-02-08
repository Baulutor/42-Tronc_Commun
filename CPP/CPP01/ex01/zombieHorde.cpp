
#include "Zombie.hpp"

Zombie	*zombieHorde(int n, string name)
{
	Zombie	*horde = new Zombie[n];

	for (int i = 0; i < n; i++)
	{
		horde[i].setName(name);
	}
	return (horde);
}

void	Zombie::setName(string str)
{
	this->_name = str;
}
