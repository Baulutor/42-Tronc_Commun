
#include "Zombie.hpp"

int main ()
{

	Zombie stackZombie("Foo");
//	Zombie heapZombie("heapZomb");

	cout << "Random  Zombie is called, announce himself and instantly destroyed after his instance in the stack is done" << endl;
	randomChump("FooFoo");

	Zombie* heapZombie = newZombie("Derick");
	heapZombie->announce();
	stackZombie.announce();
	cout << "I must delete heapZombie for calling the destructor : " << endl;
	delete heapZombie;
	cout << "The zombie who is in the stack get delete when my function main is finished" << endl;
}