#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main ()
{
	AAnimal	*l[2];
	AAnimal *p;
//	AAnimal k;
//	no instantiation possible for k, cause here we're calling the object directly



	l[0] = new Dog;
	l[1] = new Cat;


	std::cout << "the pointer of array can be instantiable cause he knows that this is a storage and not an instantiation of the object AAnimal" << std::endl;
	l[0]->makeSound();
	l[1]->makeSound();

//	p = new AAnimal;
//	we can't do that because AAnimal is an abstract class

	p = new Cat;
	std::cout << "only a pointer of AAnimal : ";
	p->makeSound();
	std::cout << std::endl << "This is working cause here my AAnimal is like a storage that I can put a object in (exactly like an array of pointer), here the Cat !" << std::endl;
	delete p;
	delete l[0];
	delete l[1];
}