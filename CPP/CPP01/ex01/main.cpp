
#include "Zombie.hpp"

int main ()
{

	std::cout << "Gonna create all the zombie horde" << std::endl;
	Zombie* heapZombie = zombieHorde(NBR_HORDE, "Foo");

	std::cout << "Gonna make zombie announce themself" << std::endl;
	for (int i = 0; i < NBR_HORDE; i++)
		heapZombie[i].announce();
	std::cout << std::endl;
	std::cout << "I must delete heapZombie for calling the destructor and not getting leaks: " << std::endl;
	delete []heapZombie;
}