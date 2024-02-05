
#include "Zombie.hpp"


Zombie::Zombie(string name)
{
	this->_name = name;
}

Zombie::~Zombie(string name)
{
	cout << name << " : has been destroyed" << endl;
}