#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main ()
{
	Animal	*l[NUMBER_ANIMAL];


	if (NUMBER_ANIMAL < 3 || NUMBER_ANIMAL > 20)
		return (std::cout << "please put a number of animal between 3 and 20" << std::endl, 1);
	for (int i = 0; i < NUMBER_ANIMAL; i++)
	{
		if (i % 2 == 0)
		{
			l[i] = new Cat();
			l[i]->makeSound();
		}
		else
		{
			l[i] = new Dog();
			l[i]->makeSound();
		}
	}
		Cat basic;
		{
			Cat tmp = basic;
		}
//		Dog basic;
//		{
//			Dog tmp = basic;
//		}
	// Showing that I create deep copy  for Cat!
	std::cout << BLUE << l[0]->getType() << std::endl;
	std::cout << l[0]->getIdea() << std::endl;
	l[0]->setIdea("go eat !");
	std::cout << l[0]->getIdea() << std::endl << std::endl;


	std::cout << l[2]->getType() << std::endl;
	std::cout << l[2]->getIdea() << RESET << std::endl;

	// While I did nothing to get idea for the dog it will use the Animal function of getIdea !
	std::cout << l[1]->getType() << std::endl;
	std::cout << l[1]->getIdea() << std::endl;
	for (int i = 0; i < NUMBER_ANIMAL; i++)
	{
		delete(l[i]);
	}
}