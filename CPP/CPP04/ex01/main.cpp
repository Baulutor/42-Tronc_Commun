#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main ()
{
	const Animal* 		meta = new Animal();
	const Animal* 		j = new Dog();
	const Animal* 		i = new Cat();


	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	cout << endl << "Normal animal working fine !" << endl << endl;
	cout << "Time to see the wrong cat !" << endl << endl;
	const WrongAnimal* 	k = new WrongCat();
	cout << k->getType() << " " << endl;
	k->makeSound();
	cout << endl << "Without the virtual word, the execution don't try to find"<< endl;
	cout << "the real object of what he hold so he keep the WrongAnimal class" << endl<< endl;
	delete(meta);
	delete(i);
	delete(j);
	delete(k);
}