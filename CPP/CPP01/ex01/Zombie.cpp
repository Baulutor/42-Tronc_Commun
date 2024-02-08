
#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie(void)
{
	cout << this->_name << " : has been destroyed" << endl;
}

void	Zombie::announce()const
{
	cout << this->_name << " : BraiiiiiiinnnzzzZ..." << endl;
}
