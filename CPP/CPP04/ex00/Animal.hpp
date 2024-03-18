
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <iostream>
# include <fstream>
# include <ostream>


class Animal {

protected:
	std::string	_type;

public:
	// CONSTRUCTOR AND DESTRUCTOR
	Animal();
	Animal(std::string type);
	Animal(Animal & src);
	Animal & operator=(Animal & rhs);
	virtual ~Animal();

	//GETTER AND SETTER
	std::string	getType() const;
	virtual void	makeSound() const;
};


#endif
