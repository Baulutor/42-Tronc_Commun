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
	std::cout << std::endl << "Normal animal working fine !" << std::endl << std::endl;
	std::cout << "Time to see the wrong cat !" << std::endl << std::endl;
	const WrongAnimal* 	k = new WrongCat();
	std::cout << k->getType() << " " << std::endl;
	k->makeSound();
	std::cout << std::endl << "Without the virtual word, the execution don't try to find"<< std::endl;
	std::cout << "the real object of what he hold so he keep the WrongAnimal class" << std::endl << std::endl;
	delete(meta);
	delete(i);
	delete(j);
	delete(k);
}