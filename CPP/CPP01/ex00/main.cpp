
#include "Zombie.hpp"

int main ()
{

	Zombie stackZombie("Foo");
//	Zombie heapZombie("heapZomb");

	std::cout << "Random  Zombie is called, announce himself and instantly destroyed after his instance in the stack is done" << std::endl;
	randomChump("FooFoo");

	Zombie* heapZombie = newZombie("Derick");
	heapZombie->announce();
	stackZombie.announce();
	std::cout << "I must delete heapZombie for calling the destructor : " << std::endl;
	delete heapZombie;
	std::cout << "The zombie who is in the stack get delete when my function main is finished" << std::endl;
}