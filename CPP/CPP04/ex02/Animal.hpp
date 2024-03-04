
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <iostream>
# include <fstream>
# include <ostream>

# define RED "\033[31m"
# define RESET "\033[0m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"

# define NUMBER_ANIMAL 3

class AAnimal {

protected:
	std::string	_type;

public:
	// CONSTRUCTOR AND DESTRUCTOR
	AAnimal();
	AAnimal(std::string type);
	AAnimal(AAnimal & src);
	AAnimal & operator=(AAnimal const & rhs);
	virtual ~AAnimal();

	//GETTER AND SETTER
	std::string		getType() const;
	virtual void	makeSound() const;
	virtual std::string getIdea() const;
	virtual void setIdea(std::string);
};


#endif
