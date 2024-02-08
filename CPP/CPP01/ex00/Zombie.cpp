
#include "Zombie.hpp"


Zombie::Zombie(string name)
{
	this->_name = name;
}

Zombie::~Zombie(void)
{
	cout << this->_name << " : has been destroyed" << endl;
}

void	Zombie::announce()const
{
	cout << this->_name << " : BraiiiiiiinnnzzzZ..." << endl;
}
