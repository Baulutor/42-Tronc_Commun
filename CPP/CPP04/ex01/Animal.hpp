
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <iostream>
# include <fstream>
# include <ostream>

# define RED "\033[31m"
# define RESET "\033[0m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"

# define NUMBER_ANIMAL 20

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
	void	getCat();
	void	getDog();
};


#endif
