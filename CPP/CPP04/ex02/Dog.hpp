//
// Created by dbaule on 2/21/24.
//

#ifndef DOG_HPP
#define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal {

private:
	Brain *_dogBrain;

public:
	// CONSTRUCTOR AND DESTRUCTOR
	Dog();
	Dog(std::string name);
	Dog(Dog & src);
	~Dog();

	// METHOD
	void makeSound() const;
};



#endif
