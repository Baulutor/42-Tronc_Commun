
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <iostream>
# include <fstream>
# include <ostream>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;


class Animal {

protected:
	string	_type;

public:
	// CONSTRUCTOR AND DESTRUCTOR
	Animal();
	Animal(string type);
	Animal(Animal & src);
	Animal & operator=(Animal & rhs);
	virtual ~Animal();

	//GETTER AND SETTER
	string	getType() const;
	virtual void	makeSound() const;
};


#endif
