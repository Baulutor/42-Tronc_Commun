
#include "Zombie.hpp"

int main ()
{

	cout << "Gonna create all the zombie horde" << endl;
	Zombie* heapZombie = zombieHorde(NBR_HORDE, "Foo");

	cout << "Gonna make zombie announce themself" << endl;
	for (int i = 0; i < NBR_HORDE; i++)
		heapZombie[i].announce();
	cout << endl;
	cout << "I must delete heapZombie for calling the destructor and not getting leaks: " << endl;
	delete []heapZombie;
}